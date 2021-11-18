#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a, b,c,n=0;
	sancf("%d %d", &a, &b);
	c = a ^ b;
	while (c)
	{
		n++;
		c = c & (c - 1);
	}
	printf("%d\n", n);
	return 0;
}