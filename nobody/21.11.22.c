#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int func(int n)
{
	int bot = n;
	int ret = n;
	while (bot > 1)
	{
		int del = bot / 2;
		ret += del;
		bot = bot % 2;
		bot += del;
	}
	return ret;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", func(n));
	return 0;
}