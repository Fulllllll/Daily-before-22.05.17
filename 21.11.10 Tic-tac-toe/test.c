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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:	
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}