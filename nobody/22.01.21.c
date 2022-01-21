#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main() {
//	int arr[4] = { 0 };
//	int i = 0;
//	for (i = 0; i < 4; i++) {
//		arr[i] = 1;
//		int ARR[4] = { arr[0] == 0,arr[2] == 1,arr[3] == 1,arr[3] == 0 };
//		int True = 0;
//		for (int i = 0; i < 4; i++)
//		{
//			True += ARR[i];
//		}
//		if (True == 3)
//		{
//			printf("%c", i + 'A');
//		}
//		arr[i] = 0;
//	}
//	return 0;
//}


//#define N 8
//
//int main()
//{
//	int i = 0, j = 0;
//	int a[N][N];
//	for (i = 0; i < N; i++)
//	{
//		a[i][0] = 1;
//		a[i][i] = 1;
//	}
//	for (i = 2; i < N; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//		}
//	}
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ",a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int cmp(int* a, int* b)
//{
//	return *a - *b;
//}
//
//int* findErrorNums(int* nums, int numsSize, int* returnSize) {
//	*returnSize = 2;
//	int* p = malloc(8);
//	qsort(nums, numsSize, 4, cmp);
//	int sum = nums[numsSize - 1];
//	for (int i = 0; i < numsSize - 1; i++)
//	{
//		sum += nums[i];
//		if (nums[i] == nums[i + 1])
//		{
//			*p = nums[i];
//		}
//	}
//	*(p + 1) = numsSize * (numsSize + 1) / 2 + *p - sum;
//	return p;
//	
//}
//#include<string.h>
//#include<assert.h>
//char* my_strstr(const char* str, const char* substr)
//{
//    assert(str && substr);
//    if (*substr == '\0')
//        return (char*)str;
//
//    char* p1 = str;
//    char* p2 = substr;
//    char* cur = str;
//    while (*cur)
//    {
//        p1 = cur;
//        p2 = substr;
//        while (*p1 == *p2 && *p1 && *p2)
//        {
//            p1++;
//            p2++;
//        }
//        if (*p2 == '\0')
//            return (char*)cur;
//        cur++;
//    }
//    return NULL;
//}
//
//int main()
//{
//	char a1[] = "abb";
//    char a2[] = "bbc";
//    char* s = my_strstr(a1, a2);
//    if (s != NULL)
//        printf("%s", s);
//    else 
//        printf("s***d");
//	return 0;
//}


#include <stdio.h>
#include <string.h>
int main()
{
    char* p = "111.222&333^&4444";
    const char* sep = ".&^";
    char arr[30];
    char* temp = NULL;
    strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
    for (temp = strtok(arr, sep); temp != NULL; temp = strtok(NULL, sep))
    {
        printf("%s\n", temp);
    }
}