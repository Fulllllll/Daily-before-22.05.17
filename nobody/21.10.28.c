#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//srand(); ����rand���������ɻ�׼��  
//rand();  �ӻ�׼�㿪ʼ����α�����

int main()			//����
{
	int n = 0;
	char ch;
	srand((unsigned int)time(NULL)); //����ʱ���������һ����������ɻ�׼��(��)��ֻ������һ�ξ���
	while ((ch=getchar()) == '1')	 
	{
		n = rand()%100;				//�ӻ�׼�㿪ʼ������α�����
		printf("%d\n", n);
		getchar();
	}
	printf("over");
	return 0;
}


//int main()			
//{
//	int n = 0;
//	char ch;
//	while ((ch = getchar()) == '1')
//	{
//		srand((unsigned int)time(NULL));     //���ö�Σ����ÿ�ζ������ƵĻ�׼�㿪ʼ�����							
//		n = rand() % 100;					//���ÿ�ζ���ӡ��׼�㣬
//		printf("%d\n", n);
//		getchar();
//	}
//	printf("over");
//	return 0;
//}


//int main()
//{
//	int n = 0;
//	char ch;
//	srand(1);   
//	while ((ch = getchar()) == '1')
//	{				
//		n = rand() % 100;					
//		printf("%d\n", n);			//��Ĭ�ϻ�׼�㿪ʼ����α�����  ��41 67 34 0 69 24
//		getchar();					//Ĭ�ϻ�׼��Ϊ 1
//	}
//	printf("over");
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	char ch;
//	while ((ch = getchar()) == '1')
//	{
//		srand((unsigned int)time(NULL));
//		n = rand() % 100;
//		printf("%d\n", n);
//		getchar();
//	}
//	printf("over");
//	return 0;
//}
