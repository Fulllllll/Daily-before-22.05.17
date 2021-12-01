#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001
int a[MAX];

int compare(const void* e1, const void* e2)
{
	return	*(int*)e1 < *(int*)e2;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int i = 0, j = 0, t = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	qsort(a, n, 4, compare);
	if (m < n)
	{
		for (i = 0; i < m - 1; i++)
		{
			printf("%d ", a[i]);
		}
		printf("%d", a[m - 1]);
	}
	if (m >= n)
	{
		for (i = 0; i < n - 1; i++)
		{
			printf("%d ", a[i]);
		}
		printf("%d", a[n - 1]);
		return 0;
	}
}
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int i = 0, j = 0, t = 0;
//	scanf("%d", &a[0]);
//	for (i = 1; i < n; i++)
//	{
//		scanf("%d", &t);
//		for (j = 0; j < i; j++)
//		{
//			if (t < a[j]) continue;
//			else
//			{
//				for (int k = i - 1; k >= j; k--)
//				{
//					a[k+1] = a[k];
//				}
//				a[j] = t;
//				break;
//			}
//		}
//		if (j >= i) a[i] = t;
//	}
//	if (m < n)
//	{
//		for (i = 0; i < m - 1; i++)
//		{
//			printf("%d ", a[i]);
//		}
//		printf("%d", a[m - 1]);
//	}
//	if (m >= n)
//	{
//		for (i = 0; i < n - 1; i++)
//		{
//			printf("%d ", a[i]);
//		}
//		printf("%d", a[n - 1]);
//	}
//}











//
//#include<iostream>
//#include<string>
//using namespace std;
//long long a[1000005];
//void swapp(long long& a, long long& b) {
//	int c;
//	c = a;
//	a = b;
//	b = c;
//}
//int main() {
//	int n, m;
//	scanf("%d %d", &n, &m);
//	for (int i = 1; i <= n; i++) {
//		scanf("%lld", &a[i]);
//	}
//	if (m > n) m = n;
//	for (int i = 1; i <= m; i++) {
//		for (int j = i + 1; j <= n; j++) {
//			if (a[i] < a[j]) swapp(a[i], a[j]);
//		}
//	}
//	printf("%d", a[1]);
//	for (int i = 2; i <= m; i++)
//		printf(" %d", a[i]);
//	return 0;
//}
//char* fun(char* s, char* t)
//{
//	char* a = s, * b = t, * a0 = s;
//	char* ret=NULL;
//	if (*b == '\0') return a;
//	while (*a0 != '\0')
//	{
//		a = a0;
//		b = t;
//		while (*a != '\0' && *b != '\0' && *a == *b)
//		{
//			a++; b++;
//		}
//		if (*b == '\0')
//			ret = a0;
//		a0++;
//	}
//	return ret;
//}
//int main()
//{
//	char s[100], t[100], * p;
//	scanf("%s", s);
//	scanf("%s", t);
//	p = fun(s, t);
//	if (p) printf("The result is : %s\n", p);
//	else printf("Not found !\n");
//}


/* 请在这里填写答案 */
//typedef int ElementType;
//typedef struct Node* PtrToNode;
//struct Node {
//    ElementType Data;
//    PtrToNode   Next;
//};
//typedef PtrToNode List;
//
//List Read(); /* 细节在此不表 */
//void Print(List L); /* 细节在此不表；空链表将输出NULL */
//
//List Merge(List L1, List L2) {
//    List p1 = L1, p2 = L2;
//    L1 = L1->Next; L2 = L2->Next;
//    List res = (List)malloc(sizeof(List));
//    List tmp = res;
//    while (L1 != NULL && L2 != NULL) {
//        if ((L1->Data) < (L2->Data)) {
//            tmp->Next = L1;
//            L1 = L1->Next;
//            tmp = tmp->Next;
//        }
//        else {
//            tmp->Next = L2;
//            L2 = L2->Next;
//            tmp = tmp->Next;
//        }
//    }
//    if (L1 != NULL) tmp->Next = L1;
//    if (L2 != NULL) tmp->Next = L2;
//    p1->Next = NULL;
//    p2->Next = NULL;
//    return res;
//}
//List Merge(List L1, List L2)
//{
//    List L = (List)malloc(sizeof(List));
//    L->Next = NULL;
//    PtrToNode p = L;
//    while (L1->Next != NULL && L2->Next != NULL)
//    {
//        if (L1->Next->Data <= L2->Next->Data)
//        {
//            p->Next = L1->Next;
//            L1->Next = L1->Next->Next;
//            p = p->Next;
//            p->Next = NULL;
//        }
//        else 
//        {
//            p->Next = L2->Next;
//            L2->Next = L2->Next->Next;
//            p = p->Next;
//            p->Next = NULL;
//        }
//    }
//    while (L1->Next != NULL)
//    {
//        p->Next = L1->Next;
//        L1->Next = L1->Next->Next;
//        p = p->Next;
//        p->Next = NULL;
//    }
//    while (L2->Next != NULL)
//    {
//        p->Next = L2->Next;
//        L2->Next = L2->Next->Next;
//        p = p->Next;
//        p->Next = NULL;
//    }
//    return L;
//}
//
//int main()
//{
//    List L1, L2, L;
//    L1 = Read();
//    L2 = Read();
//    L = Merge(L1, L2);
//    Print(L);
//    Print(L1);
//    Print(L2);
//    return 0;
//}

//int  gys(int m, int n);
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	printf("%d\n", gys(m, n));
//	return 0;
//}
//int  gys(int m, int n)
//{
//	int t;
//	while (t = m % n)
//	{
//		m = n;
//		n = t;
//	}
//	return n;
//}