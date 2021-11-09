#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b) return -1;
}
int main()
{
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	int* arr1 = (int*)malloc(m * 4);
	int* arr2 = (int*)malloc(n * 4);
	int* arr3 = (int*)malloc(m * n * 4);

	int i, j, x = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr2[i]);
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			arr3[x++] = arr1[i] * arr2[j];
		}
	}
	qsort(arr3, m * n, sizeof(int), compare);
	printf("%d", arr3[k - 1]);
	free(arr1); arr1 = NULL;
	free(arr2); arr2 = NULL;
	free(arr3); arr3 = NULL;
}


