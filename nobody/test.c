#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int i = 0;
	for (i = 101; i < 200; i++)
	{
		int j = 0;
		for (j = 2; j < i / 2; j++)
		{
			if (i % j==0) break;
		}
		if (j >= i / 2) printf("%d ", i);
	}
	return 0;
}



//int main()
//{
//	int i;
//	for (i = 1000; i < 2000; i+=4)
//	{
//		if ((i % 4 == 0 && i % 100) || i % 400 == 0)
//		{
//			printf("%d\t", i);
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int m,n,r;
//	scanf("%d %d",&m,&n);
//	while(r=m%n)
//	{
//		m=n;
//		n=r;
//	}
//	printf("%d",n);
//	return 0;
//}