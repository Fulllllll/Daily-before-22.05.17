#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void func(int a[10], int len)
{
	int left = 0, right = len - 1;
	int temp = 0;
	while (left < right)
	{
		while (left < right && a[left] % 2)
			left++;
		while (left < right && !(a[right] % 2))
			right--;
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;
	}
}

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	func(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//#include<assert.h>
//#include<string.h>
//char* Mystrcpy(char* dst, const char* src)
//{
//	assert(dst && src);
//	char* cp = dst;
//	while (*cp++ = *src++)
//	{
//		;
//	}
//	return dst;
//}
//
//int Mystrlen(const char* src)
//{
//	assert(src);
//	char* t = src;
//	int n = 0;
//	while (t++ != '\0')
//	{
//		n++;
//	}
//	return n;
//}
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}