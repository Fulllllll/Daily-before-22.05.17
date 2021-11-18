#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int num = 869;
	int a[16] = { 0 };
	int b[16] = { 0 };
	int x = num;
	for (int i = 0; i < 16; i++)
	{
		a[i] = x % 2;
		x /= 2;
		b[i] = x % 2;
		x /= 2;
	}
	for (int i = 15; i >= 0; i--)
	{
		printf("%d", a[i]);
	}
	printf("\n");
	for (int i = 15; i >= 0; i--)
	{
		printf("%d", b[i]);
	}
	return 0;
}


//int main()
//{
//	int a = 5, b = 3;
//	printf("%d %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d\n", a, b);
//}



//int count_1(x)
//{
//
//	int n = 0;
//	while (x)
//	{
//		n++;
//		x = x & (x - 1);
//	}
//	return n;
//}
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	printf("%d", count_1(x));
//	return 0;
//}

//int main()
//{
//    int a = 0, b = 0, count = 0;
//    scanf("%d %d", &a, &b);
//    int c = a ^ b;
//    while (c) 
//    {
//        count++;
//        c = c & (c - 1);
//    }
//    printf("%d\n", count);
//    return 0;
//}