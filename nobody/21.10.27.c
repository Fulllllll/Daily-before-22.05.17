#include<bits/stdc++.h>
//#define MAX 50
using namespace std;


void function(int n)
{
	if (n >= 10) function(n / 10);
	printf("%d", n % 10);
}
//void function(int n)
//{
//	if (n >= 10) function(n / 10);
//	printf("%d", n % 10);
//}
int main()
{
	function(5);
}





//typedef int element;
//typedef struct {
//	element* elem;
//	int lenth;
//	int listsize;
//}SqList;
//void initRandomize(int* arr, int n, int min, int max);
//bool InitList(SqList& L);
//void ListPrint(SqList L);
//void ListInsert(SqList& L, char e, int i);
//void function(SqList& L);
//
//int main()
//{
//	SqList L;
//	InitList(L);
//	cout << "随机生产顺序表如下：\n";
//	ListPrint(L);
//	cout << "消除后重复数据的顺序表如下：\n";
//	function(L);
//	ListPrint(L);
//}
//
//bool InitList(SqList& L)
//{
//	L.elem = (int*)malloc(MAX * sizeof(int));
//	if (!L.elem) { cout << "栈溢出" << endl; exit(-1); }
//	int n = 0;
//	cout << "输入原顺序表长度:";
//	cin >> n;
//	L.lenth = n;
//	L.listsize = MAX;
//	initRandomize(L.elem, n, 1, 6);
//}
//
//void function(SqList& L)
//{
//	element a[L.lenth];
//	int count = 0;
//	int i = 0, j = 0;
//	for (i = 0; i < L.lenth; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (L.elem[i] == L.elem[j]) break;
//		}
//		if (j >= i) a[count++] = L.elem[i];
//	}
//	L.elem = a;
//	L.lenth = count;
//}
//
//
//void ListPrint(SqList L)
//{
//	for (int i = 0; i < L.lenth; i++)
//	{
//		cout << L.elem[i] << " ";
//	}
//	cout << endl;
//}
//void initRandomize(int* arr, int n, int min, int max)
//{
//	int i = 0;
//	srand(time(0));  			/*设置种子,并生成伪随机序列*/
//	for (i = 0; i < n; ++i) {
//		arr[i] = rand() % (max - min + 1) + min;  /*得到从[min, max]之间的随机数*/
////        printf("%d ", arr[i]);
//	}
//}