#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//srand(); 设置rand函数的生成基准点  
//rand();  从基准点开始生成伪随机数

int main()			//最终
{
	int n = 0;
	char ch;
	srand((unsigned int)time(NULL)); //依靠时间戳，设置一个随机数生成基准点(数)，只需设置一次就行
	while ((ch=getchar()) == '1')	 
	{
		n = rand()%100;				//从基准点开始，生成伪随机数
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
//		srand((unsigned int)time(NULL));     //设置多次，结果每次都从相似的基准点开始随机，							
//		n = rand() % 100;					//结果每次都打印基准点，
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
//		printf("%d\n", n);			//从默认基准点开始生成伪随机数  ：41 67 34 0 69 24
//		getchar();					//默认基准点为 1
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
