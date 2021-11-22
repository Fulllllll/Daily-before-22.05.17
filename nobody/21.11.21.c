#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>

int main()
{
	int N = 13;//ÆæÊý
	int mid = N / 2 ;
	int i = 0,j=0;
	for (i = 0; i < mid + 1; i++)
	{
		for (j = 0; j < mid - i; j++)	printf(" ");
		for (j = mid - i; j < mid + 1 + i; j++)		printf("*");
		printf("\n");
	}
	for (i = mid - 1; i >= 0; i--)
	{
		for (j = 0; j < mid - i; j++)	printf(" ");
		for (j = mid - i; j < mid + 1 + i; j++)		printf("*");
		printf("\n");
	}
}
//int main()
//{
//	for (int i = 1; i < 100000;i++)
//	{
//		int sum = 0;
//		int t = 0;
//		int n = i;
//		while (t = n % 10)
//		{
//			sum += pow(t, 3);
//			n = n / 10;
//		}
//		if (sum == i)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int a = 2;
//	//scanf("%d", &a);
//	int sum = 0, temp = 0;
//	int i = 0, j = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		temp = a;
//		for (j = 0; j < i; j++)
//		{
//			temp += a*pow(10,j+1);
//		}
//		sum += temp;
//	}
//	printf("%d ", sum);
//	printf("%d", 2 + 22 + 222 + 2222 + 22222);
//	return 0;
//}


//#define  MAX 10001
//
//int main()
//{
//    char arr[MAX] = { 0 };
//    gets(arr);
//    int len = strlen(arr);
//    int mid = len / 2;
//    char t = '0';
//    for (int i = 0; i < mid; i++)
//    {
//        t = *(arr + i);
//        *(arr + i) = *(arr + len - i - 1);
//        *(arr + len - i - 1) = t;
//    }
//    printf("%s", arr);
//    return 0;
//}
//int main()
//{
//    char arr[MAX] = { 0 };
//    char t = '0';
//    int i = 0;
//    while ((t = getchar()) != EOF&& t != '\n')
//    {
//        arr[i++] = t;
//    }
//
//    int len = strlen(arr);
//    int mid = len / 2;
//    for (int i = 0; i < mid; i++)
//    {
//        t = *(arr + i);
//        *(arr + i) = *(arr + len - i - 1);
//        *(arr + len - i - 1) = t;
//    }
//    printf("%s", arr);
//      return 0;
//}

//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d  ", *(p + i));
//	}
//}