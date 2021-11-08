#include<bits/stdc++.h>
#define LIST_INIT_SIZE 20
#define LISTINCREAMENT 10
using namespace std;

typedef struct{		
	char *elem;
	int lenth;
	int listsize;
}SqList;

bool InitList(SqList& L);
void ListInsert(SqList& L,int i,char e);
void ListPrint(SqList L);
int ListLenth(SqList L);
bool ListEmpty(SqList L);
void GetElem(SqList L,int i,char& e);
int LocateElem(SqList L,char e,int& i);
void ElemDel(SqList& L,int i,char& e);
void DestroyList(SqList& L);

bool InitList(SqList& L)
{
	L.elem=(char*)malloc(LIST_INIT_SIZE*sizeof(char));
	if(!L.elem) {cout<<"栈溢出"<<endl; exit(-1);}
	L.lenth=0;
	L.listsize=LIST_INIT_SIZE;
	for(int i=0;i<5;i++)
	{
		cin>>L.elem[i];
		L.lenth++;
	}
}

void ListInsert(SqList& L,char e,int i)
{
	if(i<0||i>L.lenth)	{cout<<"i值不合法"<<endl;exit(-1);}
	if(L.lenth>=L.listsize)
	{
		char *newbase=(char*)realloc(L.elem,(L.listsize+LISTINCREAMENT)*sizeof(char));
		if(!newbase){cout<<"栈溢出"<<endl; exit(-1);}
		else L.elem=newbase;
		L.listsize+=LISTINCREAMENT;
	}
	char *q=&(L.elem[i-1]);
	char* p=NULL;
	for(p=&(L.elem[L.lenth-1]);p>=q;p--)
	{
		*(p+1)=*p;
	}
	*q = e;
	L.lenth++;
}
void ListPrint(SqList L)
{
	for(int i=0;i<L.lenth;i++)
	{
		cout<<L.elem[i]<<" ";
	}
	cout <<endl;
}
int ListLenth(SqList L){
	return L.lenth;
} 
bool ListEmpty(SqList L){
	if(L.lenth==0)	return 1;
	else return 0;
}
void GetElem(SqList L,int i,char& e){
	e=*(L.elem+i-1);
} 
int LocateElem(SqList L,char e,int& i){
	for ( i = 0; i < L.lenth; i++)
	{
		if (e==L.elem[i])
		{
			i++;
			return 1;
		} 
	}
	return 0;
}

void ElemDel(SqList& L,int i,char& e){
	if(i<0||i>L.lenth)	{cout<<"i值不合法"<<endl;exit(-1);}
	char* q=&L.elem[i-1];
	e = *q;
	char* p=&L.elem[L.lenth-1];
	for(q=&L.elem[i-1];q<p;q++)
	{
		*q=*(q+1);
	}
	L.lenth--;
}

void DestroyList(SqList& L)
{
	free(L.elem);
	L.elem = NULL;
}

int main()
{
	SqList L;
	InitList(L);
	ListPrint(L);
	cout<<"顺序表L的长度为"<<ListLenth(L)<<endl;
	if(!ListEmpty(L)) cout<<"顺序表L为非空"<<endl;
	char ch;
	GetElem(L,3,ch);
	cout<<"第三个元素为"<<ch<<endl; 
	int i=0;
	if(LocateElem(L,'a',i))
		cout<<"元素a的位置为"<<i<<endl;
	else
		cout<<"无法找到"<<endl; 
	ListInsert(L,'f',4);
	ListPrint(L);
	ElemDel(L,3,ch);
	ListPrint(L);
	DestroyList(L);
	return 0;
}
