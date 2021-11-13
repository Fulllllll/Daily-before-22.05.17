#include"game.h"

void InitBoard(char board[ROW + 2][COL + 2], int rows, int cols, char set)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Display(char board[ROW + 2][COL + 2], int row, int col)
{
	int i = 0, j = 0;
	printf("   |");
	for (i = 1; i <= col; i++)	printf("%d ", i);
	printf("\n");
	printf("   |");
	for (i = 2; i <= col+1; i++)	printf("_|");
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%3.d|", i);
		for (int j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROW + 2][COL + 2], int row, int col) 
{
	system("cls");
	int count = M_NUM;
	int x = rand() % row + 1;
	int y = rand() % col + 1;
	while (count>0)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

int Getminenum(char mine[ROW + 2][COL + 2],int x,int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1]
		+ mine[x + 1][y] + mine[x + 1][y - 1] + mine[x + 1][y + 1]) - 8 * '0';
}

void FindMine(char mine[ROW + 2][COL + 2], char show[ROW+2][COL+2],int bcount[ROW + 2][COL + 2], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;
	while (win<row*col-M_NUM)
	{
		printf("请输入要排查的坐标:>");
		scanf("%d %d", &x, &y);
		if (x>0 && x<=row && y>0 && y<=col&& show[x][y] == '*')
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾......\n");
				Display(mine, row, col);
				return;
			}
			else
			{
				Dig(mine, show, bcount, x, y, &win);
				//计算坐标周围有几个雷
				system("cls");
				//Display(mine, ROW, COL);
				//printf("\n\n");
				Display(show, ROW, COL);
			}
		}
		else
		{
			printf("输入值非法\n");
		}
	}
	printf("游戏结束，你赢了！？\n");
	system("pause");
	system("cls");
}

void Dig(char mine[ROW + 2][COL + 2], char show[ROW + 2][COL + 2], int flag[ROW + 2][COL + 2], int x, int y,int* win)
{
	if (x >= 1 && x <= ROW  && y >= 1 && y <= COL &&flag[x][y]==0)
	{
		show[x][y] = Getminenum(mine, x, y) + '0';
		flag[x][y] = 1;
		(*win)++;

		if (show[x][y] == '0')
		{
			int i = 0, j = 0;
			for (i = -1; i < 2; i++)
			{
				for (j = -1; j < 2; j++)
				{
					if (flag[x + i][y + j] == 0)
					{
						Dig(mine, show, flag, x + i, y + j, win);
						flag[x + i][y + j] = 1;
					}
				}
			}
		}
	}
	
}
