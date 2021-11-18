#include"game.h"


void menu()
{
	printf("***********************************\n");
	printf("**********    1. play    **********\n");
	printf("**********    0. exit    **********\n");
	printf("***********************************\n");
}
void game()
{
	char mine[ROW + 2][COL + 2] = { 0 };  //存放是否有雷的信息
	char show[ROW + 2][COL + 2] = { 0 };  //用来显示周围雷数
	int boomcount[ROW + 2][COL + 2] = { 0 };
	//初始化mine 数组为全字符'0'
	InitBoard(mine, ROW + 2, COL + 2, '0');
	//初始化show 数组为全字符'*'
	InitBoard(show, ROW + 2, COL + 2, '*');
	
	//初始化雷阵
	SetMine(mine, ROW, COL);
	Display(mine, ROW, COL);
	printf("\n\n");
	Display(show, ROW, COL);

	//排雷ing (正式游戏)
	FindMine(mine, show, boomcount, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while(input);
}
int main()
{
	test();
	return 0;
}