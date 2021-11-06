#include<bits/stdc++.h>
using namespace std;

typedef char element;
typedef struct LNode{
	element ch;
	struct LNode* next;
}*Link;

typedef struct LinkList{
	Link head;
	int len;
}LinkList;

bool InitList(LinkList& L);
bool InsTail(LinkList& L,element e);
bool DestoyList(LinkList& L); 
bool PrintList(LinkList L);
bool SQLinkList(LinkList& L); 
int compare(const void*e1,const void* e2);
bool Sort(element* arr,int len); 
bool Subtraction(const LinkList& A ,const LinkList& B,LinkList& C); 
bool Intersection(const LinkList& A ,const LinkList& B,LinkList& C);
bool Union(const LinkList& A ,const LinkList& B,LinkList& C); 

int main()
{
	LinkList A , B;
	InitList(A);
	InitList(B);
	//给集合 A 赋值 
	InsTail(A,'c');InsTail(A,'a');InsTail(A,'e');InsTail(A,'h');
	//给集合 B 赋值 
	InsTail(B,'f');InsTail(B,'h');InsTail(B,'b');InsTail(B,'g');InsTail(B,'d');InsTail(B,'a');
	printf("原集合A：");PrintList(A);
	printf("\n原集合B：");PrintList(B);
	//排序 
	SQLinkList(A);
	SQLinkList(B);
	printf("\n有序集合A：");PrintList(A);
	printf("\n有序集合B：");PrintList(B);
	//并集
	LinkList C;
	InitList(C);
	Union(A,B,C);
	printf("\n\nA与B的并：");PrintList(C);
	DestoyList(C);
	//交集
	LinkList D;
	InitList(D);
	Intersection(A,B,D);
	printf("\nA与B的交：");PrintList(D);
	DestoyList(D);
	//差集
	LinkList E;
	InitList(E);
	Subtraction(A,B,E);
	printf("\nA与B的差：");PrintList(E);
	DestoyList(E);
	
	DestoyList(A);
	DestoyList(B);
	
}












bool InitList(LinkList& L)
{
	L.head=(Link)malloc(sizeof(LNode));
	if (!L.head) 
	{
		printf("%s\n", strerror(errno));   exit(-1);
	}
	L.head->next=NULL;
	L.len=0;
	return 1;
}
bool InsTail(LinkList& L,element e)
{
	Link p=L.head;
	while(p->next)
	{
		p=p->next;
	}
	Link node=(Link)malloc(sizeof(LNode));
	if (!node) 
	{
		printf("%s\n", strerror(errno));   exit(-1);
	}
	node->next=NULL;
	node->ch=e;
	p->next=node;
	L.len++;
	return 1;
}
bool DestoyList(LinkList& L)
{
	Link p=NULL;
	while(L.head->next)
	{
		p=L.head->next;
		L.head->next=p->next;
		free(p);
		p=NULL;
		L.len--;
	}
	L.len=0;
	return 1;
}
bool PrintList(LinkList L)
{
	Link p=L.head->next;
	while(p)
	{
		printf("%c  ",p->ch);
		p=p->next;
	}
	return 1;
}

int compare(const void*e1,const void* e2)
{
	return *((char*)e1)-*((char*)e2);
}
bool SQLinkList(LinkList& L)
{
	element* arr=(element*)malloc(L.len);
	Link p=L.head->next;
	for(int i=0;i<L.len;i++)
	{
		arr[i]=p->ch;
		p=p->next;
	}
	qsort(arr,L.len,sizeof(arr[0]),compare);
	p=L.head->next;
	for(int i=0;i<L.len;i++)
	{
		p->ch=arr[i];
		p=p->next;
	}
	free(arr);
	arr=NULL;
	return 1;
}

bool Subtraction(const LinkList& A ,const LinkList& B,LinkList& C)
{
	Link p1=A.head->next;
	while(p1)
	{
		Link p2=B.head->next;
		while(p2)
		{
			if(p2->ch==p1->ch) break;
			p2=p2->next;		
		}		
		if(!p2) InsTail(C,p1->ch);
		p1=p1->next;
	}
	SQLinkList(C);
	return 1;
}
bool Intersection(const LinkList& A ,const LinkList& B,LinkList& C)
{
	Link p1=A.head->next;
	while(p1)
	{
		Link p2=B.head->next;
		while(p2)
		{
			if(p2->ch==p1->ch) break;
			p2=p2->next;		
		}		
		if(p2) InsTail(C,p1->ch);
		p1=p1->next;
	}
	SQLinkList(C);
	return 1;
}

bool Union(const LinkList& A ,const LinkList& B,LinkList& C)
{
	LinkList T;
	InitList(T);
	Subtraction(B,A,T);
	Link p1=A.head->next;
	while(p1)
	{
		InsTail(C,p1->ch);
		p1=p1->next;	
	}
	Link p2=T.head->next;
	while(p2)
	{
		InsTail(C,p2->ch);
		p2=p2->next;
	}
	DestoyList(T);
	SQLinkList(C);
}




