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
int ListLength(LinkList L);
bool ListEmpty(LinkList L);
bool InsertList(LinkList& L,int i,element e);
bool DeleteElem(LinkList& L,int i,element& e); 

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
int ListLength(LinkList L)
{
	return L.len;
} 
bool ListEmpty(LinkList L)
{
	if(L.len==0) return 1;
	else return 0;
}

bool LocateElem(LinkList L,int i,element& ch)
{
	if(i<=0||i>L.len) {printf("i值不合法\n");   exit(-1);}
	Link p=L.head->next;
	int count=1; 
	while(p&&count<i)
	{
		p=p->next;
		count++;
	}
	ch=p->ch;
	return 1;
}
bool LocatePos(LinkList L,int& i,element ch)
{
	Link p=L.head->next;
	int count=1;
	while(p&&p->ch!=ch)
	{
		count++;
		p=p->next;
	}
	if(p)	i=count;
	else 	i=0; 
	return 1;
}
bool InsertList(LinkList& L,int i,element e)
{
	if(i<=0||i>L.len+1) {printf("i值不合法\n");   exit(-1);}
	Link ins=(Link)malloc(sizeof(LNode));
	ins->ch=e;
	Link p=L.head;
	int count=1;
	while(count<i)
	{
		count++;
		p=p->next;
	}
	ins->next=p->next;
	p->next=ins;
	L.len++;
	return 1;
} 

bool DeleteElem(LinkList& L,int i,element& e)
{
	if(i<=0||i>L.len){printf("i值不合法\n");   exit(-1);}
	Link p=L.head;
	int count=1;
	while(count<i)
	{
		p=p->next;
		count++;
	}
	Link q=p->next;
	e=q->ch;
	p->next=q->next;
	free(q);
	q=NULL;
	L.len--;
	return 1;
}


int main()
{
	LinkList L;
	cout<<"初始化单链表head......"<<endl; 
	InitList(L);
	cout<<"依次采用尾插法插入a,b,c,d,e元素"<<endl; 
	InsTail(L,'a');InsTail(L,'b');InsTail(L,'c');InsTail(L,'d');InsTail(L,'e');
	cout<<"输出单链表"<<endl; 
	PrintList(L);
	cout<<"\n单链表的长度为"<<ListLength(L)<<endl;
	if(ListEmpty(L)==0)cout << "单链表非空"<<endl;
	
	char ch;
	int i;
	LocateElem(L,3,ch);	
	cout<<"第三个元素为"<<ch<<endl;
	LocatePos(L,i,'a');
	if(i)cout<<"a的位置为第"<<i<<"个"<<endl; 
	else cout<<"单链表中没有该元素"<<endl; 
	cout<<"在第4个元素位置上插入f元素"<<endl;
	InsertList(L,4,'f');
	PrintList(L);cout<<endl;
	cout<<"删除head的第3个元素"<<endl;
	DeleteElem(L,3,ch);
	PrintList(L);cout<<endl;
	DestoyList(L);
	return 0;
}

