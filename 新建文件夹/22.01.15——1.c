#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//int func(int n)
//{
//	if (n == 1) return 1;
//	if (n == 2) return 2;
//	return func(n - 1) + func(n - 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	printf("%d", func(n));
//	return 0;
//}


//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	int ret = 0;
//	int n = -1;
//
//	while (x)
//	{
//		n++;
//		int temp = (x % 10) & 1;
//		ret += temp * (int)pow(10, n);
//		x = x / 10;
//	}
//
//	printf("%d", ret);
//	return 0;
//}


//int compare(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//	int arr[100000 + 10] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, n, 4, compare);
//	
//	int cur = -1;
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] != cur)
//		{
//			printf("%d ", arr[i]);
//			cur = arr[i];
//		}
//	}
//	return 0;
//}


//int main()
//{
//	long n = 0;
//	scanf("%d", &n);
//	printf("%d", (n / 12) * 4 + 2);
//	return 0;
//}

//int main()
//{
//	int n = 0, m = 0;
//	int arr[10][10] = { 0 };
//	scanf("%d %d", &n, &m);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%d ", arr[j][i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int N = 0, n = 0;
//	int arr[50] = { 0 };
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	scanf("%d", &n);
//	for (int i = 0; i < N; i++)
//	{
//		if (arr[i] != n)
//		printf("%d",arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = 1;
//	for (int i = 0; i < n; i++)
//	{
//		ret <<= 1;
//	}
//	printf("%d", ret);
//	return 0;
//}

//void PRINT(int n)
//{
//	printf("*\n");
//	for (int i = 0; i < n - 2; i++)
//	{
//		printf("*");
//		for (int j = 0; j < i * 2 + 1; j++)
//		{
//			printf(" ");
//		}
//		printf("*\n");
//	}
//	for (int i = 0; i < n; i++) printf("* ");
//	printf("\n");
//}
//int main()
//{
//	int n = 0;
//	while (~scanf(" %d", &n))
//	{
//		PRINT(n);
//	}
//	return 0;
//}
//void PRINT(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//			printf("  ");
//		for (int k = 0; k < i + 1; k++)
//			printf("* ");
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int n = 0;
//	while (~scanf(" %d", &n))
//	{
//		PRINT(n);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[7] = { 0 };
//	while (~scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]))
//	{
//		int min = 0, max = 0;
//		for (int i = 1; i < 7; i++)
//		{
//			if (arr[i] < arr[min]) min = i;
//			if (arr[i] > arr[max]) max = i;
//		}
//		arr[min] = 0;
//		arr[max] = 0;
//		int sum = 0;
//		for (int i = 0; i < 7; i++)
//		{
//			sum += arr[i];
//		}
//		printf("%.2f\n", sum / 5.0);
//	}
//	return 0;
//}
//int main()
//{
//	double a = 0, b = 0, c = 0;
//	double x1 = 0, x2 = 0;
//
//	while (~scanf("%lf %lf %lf", &a, &b, &c))
//	{
//		if (a == 0) printf("Not quadratic equation\n");
//		else
//		{
//			double delta = pow(b, 2) - 4 * a * c;
//			if (delta == 0)
//			{
//				printf("x1=x2=%.2lf\n", (-b + sqrt(delta)) / (2 * a));
//			}
//			else if (delta > 0)
//			{
//				printf("x1=%.2lf;x2=%.2lf\n", (-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a));
//			}
//			else if (delta < 0)
//			{
//				printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi\n", (-b) / (2 * a), sqrt(-delta) / (2 * a), (-b) / (2 * a), sqrt(-delta) / (2 * a));
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	double a = 0, b = 1;
//	double c = 0.0;
//	printf("%.2lf\n", a);
//	printf("%.2lf\n",-a);
//	printf("%lf\n", b-1);
//	printf("%lf\n", b-1);
//	printf("%lf\n", a);
//	return 0;
//}

int main()
{
	int year = 0, month = 0;
	while(~scanf("%d %d", &year, &month))
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("31\n");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30\n");
			break;
		case 2:
			if ((year%100!=0&&year%4==0)||(year%100==0&&year%400==0)) printf("29\n");
			else printf("28\n");
		default:
			break;
		}
	}

	return 0;
}