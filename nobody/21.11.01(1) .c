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
		printf("��������µ�����");
		scanf("%d", &x);
		count++;
		if (x > N) printf("�´���\n");
		else if (x < N) printf("��С��\n");
		else
		{
			printf("�¶��ˣ�������%d��\n",count);
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
		printf("��ѡ��>>");
		ch=getchar();
		if (ch == '1')	
		{
			N = rand() % 100;
			game(N);
			system("pause");
			printf("���������������\n");
			system("cls");
		}
		else printf("��Ϸ����\n");
		getchar();
	} while (ch == '1');
	return 0;
}
