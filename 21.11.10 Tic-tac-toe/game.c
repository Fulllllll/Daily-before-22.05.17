#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1) printf("|");
		}
		printf("\n");
		for (int k = 0; k < col ; k++)
		{
			if (i == row - 1) break;
			printf("---");
			if (k < col - 1) printf("|");
		}
		printf("\n");
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	int x=0, y=0;
	printf("玩家下子, 请输入落子坐标:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x > 0 && y > 0 && x <= row && y <= col && board[x-1][y-1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			break; 
		}
		else printf("坐标非法，请重新输入:>");
	}
}
void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑下棋ing\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}


int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == is_full(board, row, col))
	{
		return 'Q';
	}
	return 'C';
}