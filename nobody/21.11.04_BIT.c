#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



int F1(int n)
{
	if (n == 1 || n == 2) return 1;
	return F1(n - 2) + F1(n - 1);
}

int F2(int n)
{
	int sum = 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n > 2)
	{
		int x1 = 1, x2 = 1, sum = 0;
		for (int i = 0; i < n-2; i++)
		{
			sum = x1 + x2;
			x1 = x2;
			x2 = sum;
		}
		return sum;
	}

}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", F1(n));
	printf("%d\n", F2(n));
	return 0;
}




//int function(int n, int k)
//{
//	if (k == 0) return 1;
//	return n * function(n, k - 1);
//}
//int main()
//{
//	printf("%d", function(2,3));
//	return 0;
//}

//int DigitSum(n)
//{
//	if (n < 10) return n;
//	int x = n % 10;
//	return x + DigitSum(n / 10);
//}
//
//int main()
//{
//	printf("%d", DigitSum(1548));
//	return 0;
//}


//void function(int n)
//{
//	if (n < 0)
//	{
//		printf("-");
//		function(-n);
//	}
//	if (n >= 0)
//	{
//		if (n >= 10) function(n / 10);
//		printf("%d", n % 10);
//	}
//}
//
//int main()
//{
//	function(-451); printf("\n");
//	function(-6); printf("\n");
//	function(0); printf("\n");
//	function(9); printf("\n");
//	function(856); printf("\n");
//}

//int function1(int n)
//{
//	if (n == 1) return 1;
//	return n * function1(n-1);
//}
//int function2(int n)
//{
//	int i = 0 , sum = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//}
//
//int main()
//{
//	printf("%d\n", function1(5));
//	printf("%d\n", function2(5));
//}

//int function1(char* p)
//{
//	if (*p == '\0') return 0;
//	return 1 + function1(p + 1);
//}
//int function2(char* p)
//{
//	int i = 0;
//	while ((*p) != '\0')
//	{
//		i++;
//		p++;
//	}
//	return i;
//}
//
//int main()
//{
//	char arr[] = "asdfg";
//	printf("%d\n", function1(arr));
//	printf("%d\n", function2(arr));
//}


//int len(char* string)
//{
//	int i = 0;
//	while (*string)
//	{
//		i++;
//		string++;
//	}
//	return i;
//}
//
//void function(char* string)
//{
//	int l = len(string);
//	if (l == 1) return ;
//	if (l == 2)
//	{
//		int first = 0, end = l - 1;
//		char ex = string[first];
//		string[first] = string[end];
//		string[end] = ex;
//	}
//	if (l > 2)
//	{
//		char* temp = (char*)malloc(l - 1);
//		for (int i = 0; i < l - 2; i++)
//		{
//			temp[i] = string[i + 1];
//		}
//		temp[l - 2] = '\0';
//		function(temp);
//		for (int i = 0; i < l - 2; i++)
//		{
//			string[i+1] = temp[i];
//		}
//	}
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	function(arr);
//	printf("%s", arr);
//	return 0;
//}

