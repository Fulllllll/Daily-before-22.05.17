#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void PrintArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}
void exchange(int* a, int* b, int len)
{
	for (int i = 0; i < len; i++)
	{
		swap(&a[i], &b[i]);
	}
}

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int b[10] = { 4,5,2,1,3,6,9,7,8,0 };
	printf("数组a：");
	PrintArr(a, 10);
	printf("数组b：");
	PrintArr(b, 10);
	printf("交换数组元素......\n");
	exchange(a, b, 10);
	printf("数组a：");
	PrintArr(a, 10);
	printf("数组b：");
	PrintArr(b, 10);
}
//void InitArr(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void PrintArr(int* arr, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void reverse(int* arr, int len)
//{
//	for (int i = 0; i < len / 2; i++)
//	{
//		int x = arr[i];
//		arr[i] = arr[len - 1 - i];
//		arr[len - 1 - i] = x;
//	}
//}
//
//int main()
//{
//	int arr[10];
//	printf("不初始化直接申请数组："); PrintArr(arr, 10);
//	int len = sizeof(arr) / sizeof(arr[0]);
//	InitArr(arr, len);
//	printf("初始化数组："); PrintArr(arr, len);
//	for (int i = 0; i < len; i++)
//	{
//		arr[i] = i;
//	}
//	printf("数组赋值："); PrintArr(arr, len);
//	reverse(arr, len);
//	printf("逆置数组："); PrintArr(arr, len);
//	return 0;
//}

//void swap(int* a, int* b)
//{
//	int x = *a;
//	*a = *b;
//	*b = x;
//}
//void func(int* arr[], int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len - 1; j++)
//		{
//			if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
//		} 
//	}
//}
//int main()
//{
//	int a[10] = { 2,3,6,8,4,9,5,1,0,7};
//	int len = sizeof(a) / sizeof(a[0]);
//	func(a, len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%d  ", a[i]);
//	}
//}