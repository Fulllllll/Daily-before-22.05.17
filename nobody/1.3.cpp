#include<bits/stdc++.h>
#define MAX 50
using namespace std;

typedef int element;
typedef struct {
	element* elem;
	int lenth;
	int listsize;
}SqList;
void initRandomize(int* arr, int n, int min, int max);
bool InitList(SqList& L);
void ListPrint(SqList L);
void ListInsert(SqList& L, char e, int i);
void function(SqList& L);

int main()
{
	SqList L;
	InitList(L);
	cout << "�������˳������£�\n";
	ListPrint(L);
	cout << "�������ظ����ݵ�˳������£�\n";
	function(L);
	ListPrint(L);
}

bool InitList(SqList& L)
{
	L.elem = (int*)malloc(MAX * sizeof(int));
	if (!L.elem) { cout << "ջ���" << endl; exit(-1); }
	int n = 0;
	cout << "����ԭ˳�����:";
	cin >> n;
	L.lenth = n;
	L.listsize = MAX;
	initRandomize(L.elem, n, 1, 6);
}

void function(SqList& L)
{
	element a[MAX];
	int count = 0;
	int i = 0, j = 0;
	for (i = 0; i < L.lenth; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (L.elem[i] == L.elem[j]) break;
		}
		if (j >= i) a[count++] = L.elem[i];
	}
	L.lenth=count;
	for(i=0;i<count;i++)
	{
		L.elem[i]=a[i];
	}
}


void ListPrint(SqList L)
{
	for (int i = 0; i < L.lenth; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl;
}
void initRandomize(int* arr, int n, int min, int max)
{
	int i = 0;
	srand(time(0));  			/*��������,������α�������*/
	for (i = 0; i < n; ++i) {
		arr[i] = rand() % (max - min + 1) + min;  /*�õ���[min, max]֮��������*/
//        printf("%d ", arr[i]);
	}
}


