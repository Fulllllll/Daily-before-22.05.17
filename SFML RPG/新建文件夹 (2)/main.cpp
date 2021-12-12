#include<stdio.h>
#include<time.h>
#include<iostream>
#include <Windows.h>
#include<vector>
#include<queue>
#include<SFML/Graphics.hpp>

#define R 44
#define L 74
#define WALLPROB 40
int map[R][L];

void CA3()
{
	int x = 0, y = 0;
	for (y = 1; y < L - 1; ++y)
	{
		for (x = 1; x < R - 1; ++x)
		{
			int r1 = 0;
			for (int dy = -1; dy <= 1; ++dy)
			{
				for (int dx = -1; dx <= 1; ++dx)
				{
					if (map[x + dx][y + dy] == 1)
						r1++;
				}
			}
			if (r1 >= 5)
				map[x][y] = 1;
			else
				map[x][y] = 0;
		}
	}
}
int Inmap(int x, int y)
{
	return x >= 0 && x < R && y >= 0 && y < L;
}
void CA5()
{
	int x = 0, y = 0;
	for (y = 1; y < L - 1; ++y)
	{
		for (x = 1; x < R - 1; ++x)
		{
			int r1 = 0, r2 = 0;
			for (int dy = -2; dy <= 2; ++dy)
			{
				for (int dx = -2; dx <= 2; ++dx)
				{
					int ax = std::abs(dx);
					int ay = std::abs(dy);
					if (ax == 2 && ay == 2)
						continue;
					if (Inmap(x + dx, y + dy) && map[x+dx][y+dy] == 1)
					{
						if (ax <= 1 && ay <= 1)
							r1 += 1;
						r2 += 1;
					}
				}
			}
			if (r1 >= 5 || r2 <= 2)
				map[x][y] = 1;
			else
				map[x][y] = 0;
		}
	}
}

void removeRegions(int removeProb = 100, int minSize = 0);
using Point = sf::Vector2i;
void removeRegions(int removeProb, int minSize)
{
	int currentRegion = -1;
	std::vector<int> regions(R*L, currentRegion);
	std::vector<int> regionsSizes;
	for (int y = 1; y < L - 1; ++y)
		for (int x = 1; x < R - 1; ++x)
		{
			if (map[x][y] == 1 || regions[x + y * L] >= 0)
				continue;

			currentRegion += 1;
			regionsSizes.emplace_back(0);

			std::queue<Point> queue;
			queue.emplace(x, y);

			while (!queue.empty())
			{
				Point pos = queue.front();
				queue.pop();

				if (map[pos.x][pos.y] == 1 || regions[pos.x + pos.y * L] >= 0)
					continue;

				regions[pos.x + pos.y * L] = currentRegion;
				regionsSizes[currentRegion] += 1;

				Point dpos[4] = { {0,1},{0,-1},{1,0},{-1,0} };
				for (int i=0;i<4;i++)
				{
					if(!Inmap(pos.x+dpos[i].x,pos.y + dpos[i].y))
						continue;

					queue.emplace(pos.x + dpos[i].x, pos.y + dpos[i].y);

				}
			}
		}
	// Find the biggest region
	int biggestRegion = 0;
	std::vector<bool> regionsForRemoval(currentRegion + 1, false);

	for (int i = 0; i <= currentRegion; ++i)
	{
		if (regionsSizes[i] > regionsSizes[biggestRegion])
			biggestRegion = i;

		if (rand() % 100 + 1 < removeProb || regionsSizes[i] < minSize)
			regionsForRemoval[i] = true;
	}
	// Always do not remove the biggest region
	regionsForRemoval[biggestRegion] = false;
	for (int y = 1; y < L - 1; ++y)
		for (int x = 1; x < R - 1; ++x)
		{
			if (map[x][y] == 1)
				continue;

			int i = regions[x + y * L];

			if (regionsForRemoval[i])
				map[x][y] = 1;
		}
}
void removeWallChunks()
{
	for(int y=0;y<L;y++)
		for (int x = 0; x < R; x++)
		{
			if (map[x][y] == 1) map[x][y] = 0;
			if (map[x][y] == 0) map[x][y] = 1;
		}
	removeRegions();
	for (int y = 0; y < L; y++)
		for (int x = 0; x < R; x++)
		{
			if (map[x][y] == 1) map[x][y] = 0;
			if (map[x][y] == 0) map[x][y] = 1;
		}
}

int main()
{
	int x = 0, y = 0, i = 0, j = 0;
	srand((unsigned) time(NULL));
	//for (i = 0; i < 75; i++) rand();

//生成噪化图      WALLPROB  -----------------------------------------------------------------------------------------------
	for (y = 0; y < L; ++y)
		for (x = 0; x < R; ++x)
		{
			if (x == 0 || x == R - 1 || y == 0 || y == L - 1)
				map[x][y] = 1;
			else if (rand() % 100 < WALLPROB)
				map[x][y] = 1;
			else
				map[x][y] = 0;
		}
//原孢 处理5*5-----------------------------------------------------------------------------------------------
	for (i = 0; i < 4; i++) CA5();
//原孢 处理3*3-----------------------------------------------------------------------------------------------
	for (i = 0; i < 3; i++) CA3();
//洪水填充
	removeRegions();
	removeWallChunks();

//打印-----------------------------------------------------------------------------------------------
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < L; j++)
		{
			if (map[i][j] == 1) printf("□");
			else if (map[i][j] == 0) printf("  ");
		}
		printf("\n");
	}
}