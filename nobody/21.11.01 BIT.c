#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int is_prime(int n)
//{
//	int i=0;
//	for (i = 2; i < n / 2; i++)
//	{
//		if (n % i == 0) break;
//	}
//	if (i >= n / 2) return 1;
//	else return 0;
//}
//
//int is_ryear(int y)
//{
//	if (((y % 4 == 0) && (y % 100)) || (y % 400 == 0))
//		return 1;
//	else return 0;
//}
//
//void swap(int* a, int* b)
//{
//	int x = *a;
//	*a = *b;
//	*b = x;
//}
//
//
//int main()
//{
//	int a = 1, b = 0;
//	printf("%d %d\n", a, b);
//	swap(&a, &b);
//	printf("%d %d", a, b);
//}


void function()
{
	int X;
	scanf("%d", &X);
	int i = 1, j = 1;
	for (i = 1; i <= X; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%2.d\t", j, i, i * j);
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	function();
}