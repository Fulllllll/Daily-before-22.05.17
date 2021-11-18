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
	char mine[ROW + 2][COL + 2] = { 0 };  //����Ƿ����׵���Ϣ
	char show[ROW + 2][COL + 2] = { 0 };  //������ʾ��Χ����
	int boomcount[ROW + 2][COL + 2] = { 0 };
	//��ʼ��mine ����Ϊȫ�ַ�'0'
	InitBoard(mine, ROW + 2, COL + 2, '0');
	//��ʼ��show ����Ϊȫ�ַ�'*'
	InitBoard(show, ROW + 2, COL + 2, '*');
	
	//��ʼ������
	SetMine(mine, ROW, COL);
	Display(mine, ROW, COL);
	printf("\n\n");
	Display(show, ROW, COL);

	//����ing (��ʽ��Ϸ)
	FindMine(mine, show, boomcount, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while(input);
}
int main()
{
	test();
	return 0;
}