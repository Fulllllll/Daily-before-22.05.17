#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int len(char* string)
{
	int i = 0;
	while (*string)
	{
		i++;
		string++;
	}
	return i;
}

void exchange(char* string, int front, int tail)
{
	char ex = string[front];
	string[front] = string[tail];
	string[tail] = ex;
}
void function(char* string)
{
	int l = len(string);
	if (l == 1) return;
	if (l == 2)
	{
		exchange(string, 0, l - 1);
	}
	if (l > 2)
	{
		exchange(string, 0, l - 1);

		char* temp = (char*)malloc(l - 1);
		for (int i = 0; i < l - 2; i++)
		{
			temp[i] = string[i + 1];
		}
		temp[l - 2] = '\0';
		function(temp);
		for (int i = 0; i < l - 2; i++)
		{
			string[i + 1] = temp[i];
		}
	}
}

int main()
{
	char arr[] = "abcdef";
	function(arr);
	printf("%s", arr);
	return 0;
}