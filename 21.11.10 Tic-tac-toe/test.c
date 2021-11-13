#include"game.h"
void menu()
{
	printf("****************************\n");
	printf("*******   1. paly    *******\n");
	printf("*******   0. exit    *******\n");
	printf("****************************\n");

}
void game()
{
	system("cls");
	char board[ROW][COL] = { ' ' };
	InitBoard(board, ROW, COL);
	srand((unsigned)time(NULL));
	DisplayBoard(board, ROW, COL);
	char ret = '0';
	while (1)
	{
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:	
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}