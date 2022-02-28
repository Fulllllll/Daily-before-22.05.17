#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<bits/stdc++.h>
#include <string.h>
int fun(int a)
{
	a ^= (1 << 5) - 1;
	return a;
}
int main()
{
	printf("%d", fun(21));
}