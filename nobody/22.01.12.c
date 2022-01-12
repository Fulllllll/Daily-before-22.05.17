#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int func(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	return func(n - 1) + func(n - 2);
}
int main()
{
	int n = 0;
	scanf("%d", &n);

	printf("%d", func(n));
	return 0;
}


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



