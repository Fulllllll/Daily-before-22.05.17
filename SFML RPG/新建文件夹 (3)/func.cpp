#include"func.h"


void CA3(int map[ROW][COL], int i, int j)
{
	int sum = 0;
	for (int a = -1; a <= 1; a++)
	{
		for (int b = -1; b <= 1; b++)
		{
			if (a == 0 && b == 0) continue;
			if (map[i + a][j + b] == 0) sum++;
		}
	}
	if (sum > 4) map[i][j] = 0;
	if (sum < 4) map[i][j] = 1;
}

int isInBounds(int x, int y)
{
	return x >= 0 && x < ROW&& y >= 0 && y < COL;
}
void Init_Map(int map[ROW][COL])
{
	for (int i = 0; i < ROW ; i++)
	{
		for (int j = 0; j < COL ; j++)
		{
			map[i][j] = 1;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////
	//1
	srand(time(NULL));
	int x = 0, y = 0;
	for (int i = 0; i < VBLOCK;)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (map[x - 1][y - 1] == 0 && x != 1 && x != ROW && y != 1 && y != COL)
		{
			map[x - 1][y - 1] = 0;
			i++;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////

	//2
	for (int k = 0; k < 4; k++)
	{
		for (int i = 1; i < ROW - 1; i++)
		{
			for (int j = 1; j < COL - 1; j++)
			{
				CA3(map, i, j);
			}
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////
	//for (int i = 1; i < ROW - 1; i++)
	//{
	//	for (int j = 1; j < COL - 1; j++)
	//	{
	//		int r1 = 0;
	//		int r2 = 0;
	//		for (int dy = -2; dy <= 2; ++dy)
	//			for (int dx = -2; dx <= 2; ++dx)
	//			{
	//				int ax = std::abs(dx);
	//				int ay = std::abs(dy);

	//				if (ax == 2 && ay == 2)
	//					continue;

	//				if (isInBounds(x + dx, y + dy) &&
	//					map[x + dx][y + dy] == 1)
	//				{
	//					if (ax <= 1 && ay <= 1)
	//						r1 += 1;
	//					r2 += 1;
	//				}
	//			}
	//		if (r1 >= 5 || r2 <= 2)
	//			map[x][y] = 1;
	//		else
	//			map[x][y] = 0;
	//	}
	//}
////////////////////////////////////////////////////////////////////////////////////////////


}
void Show_Map(int map[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (map[i][j] == 1)	printf(" ");
			if (map[i][j] == 0)	printf("#");
		}
		cout << endl;
	}
}