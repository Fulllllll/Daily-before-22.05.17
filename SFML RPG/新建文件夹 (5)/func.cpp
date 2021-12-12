#include"func.h"


void CA(int map[ROW][COL], int i, int j)
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

void Init_Map(int map[ROW][COL])
{
	//1
	srand(time(NULL));
	int x = 0, y = 0;
	for (int i = 0; i < VBLOCK;)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (map[x - 1][y - 1] == 0 && x != 1 && x != ROW && y != 1 && y != COL)
		{
			map[x - 1][y - 1] = 1;
			i++;
		}
	}
	//2
	for (int k = 0; k < 4; k++)
	{
		for (int i = 1; i < ROW - 1; i++)
		{
			for (int j = 1; j < COL - 1; j++)
			{
				CA(map, i, j);
			}
		}
	}

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