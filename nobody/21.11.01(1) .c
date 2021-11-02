#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void game(int N) 
{
	int x = 0, count = 0;
	while (1)
	{
		printf("请输入你猜的数：");
		scanf("%d", &x);
		count++;
		if (x > N) printf("猜大了\n");
		else if (x < N) printf("猜小了\n");
		else
		{
			printf("猜对了，共猜了%d次\n",count);
			return;
		}
	}

}
int main()
{
	char ch;
	int N = 0;
	srand((unsigned)time(NULL));
	do {
		printf("************************************\n");
		printf("****           1. play          ****\n");
		printf("****           2. exit          ****\n");
		printf("************************************\n");
		printf("请选择：>>");
		ch=getchar();
		if (ch == '1')	
		{
			N = rand() % 100;
			game(N);
			system("pause");
			printf("请输入任意键继续\n");
			system("cls");
		}
		else printf("游戏结束\n");
		getchar();
	} while (ch == '1');
	return 0;
}
