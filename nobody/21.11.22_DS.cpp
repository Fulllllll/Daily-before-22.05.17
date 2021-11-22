#include<bits/stdc++.h>
#define MAX_SIZE 5
using namespace std;
typedef char ElemType;

//栈 
typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
}Sqstack;
bool InitStack(Sqstack& S);
void Push(Sqstack& S, ElemType x);
ElemType Pop(Sqstack& S);
bool StackFull(Sqstack S);
bool StackEmpty(Sqstack S);
bool Display(Sqstack S);

bool InitStack(Sqstack& S)
{
	S.base = (ElemType*)malloc(MAX_SIZE * sizeof(ElemType));
	if (!S.base) exit(-1);
	S.top = S.base;
	S.stacksize = MAX_SIZE;
	return 1;
}
void Push(Sqstack& S, ElemType e)
{
	*(S.top++) = e;
}
ElemType Pop(Sqstack& S)
{
	ElemType e = '0';
	if (S.base == S.top)
	{
		cout << "栈空,pop失败";
		exit(-1);
	}
	e = *(--S.top);
	return e;
}
bool StackEmpty(Sqstack S)
{
	return (S.top - S.base == 0);
}
bool StackFull(Sqstack S)
{
	return(S.top >= S.base + S.stacksize);
}
bool Display(Sqstack S)
{
	ElemType* p = S.base;
	while (p != S.top)
	{
		cout << *(p++) << " ";
	}
	return 1;
}

//两个栈组成的队列  
typedef struct {
	Sqstack a;
	Sqstack b;
}Queue;

bool InitQueue(Queue& Q);
bool EnQueue(Queue& Q, ElemType x);
ElemType DeQueue(Queue& Q);
void DisplayQ(Queue& Q)
{
	cout << "队列："<<endl;
	cout << "\t栈a："; 
	Display(Q.a);
	cout << endl<<"\t栈b：";
	Display(Q.b);
	cout << endl;
	cout << endl;
}

bool InitQueue(Queue& Q)
{
	InitStack(Q.a);
	InitStack(Q.b);
	return 1;
}
bool EnQueue(Queue& Q, ElemType x)
{
	if (StackFull(Q.a) && !StackEmpty(Q.b))//队列满：栈a满，栈b非空
	{
		cout << "队列满,入队失败";
		return 0;
	}
	if (!StackFull(Q.a))//队列未满：栈a未满
	{
		Push(Q.a, x);
		return 1;
	}
	if (StackFull(Q.a) && StackEmpty(Q.b))//队列未满：栈a未满，栈b为空
	{
		ElemType t;
		while (!StackEmpty(Q.a))
		{
			t = Pop(Q.a);
			Push(Q.b, t);
		}
		Push(Q.a, x);
		return 1;
	}
	
}
ElemType DeQueue(Queue& Q)
{
	if(StackEmpty(Q.a)&& StackEmpty(Q.b))
	{
		cout << "队列空,出队失败";
		return 0;
	}
	if (!StackEmpty(Q.b))
	{
		return Pop(Q.b);
	}
	if (!StackEmpty(Q.a) && StackEmpty(Q.b))
	{
		ElemType t;
		while (!StackEmpty(Q.a))
		{
			t = Pop(Q.a);
			Push(Q.b, t);
		}
		return Pop(Q.b);
	}
}
int main()
{
	Queue Q;
	InitQueue(Q);
	DisplayQ(Q);
	cout << "此时栈空,执行出队列函数..." << endl;
	DeQueue(Q);
	cout << endl << endl;

	cout << "入队列abcde" << endl;
	EnQueue(Q, 'a');
	EnQueue(Q, 'b');
	EnQueue(Q, 'c'); 
	EnQueue(Q, 'd'); 
	EnQueue(Q, 'e'); 
	DisplayQ(Q);

	cout << "出队列:" << DeQueue(Q) << endl;
	DisplayQ(Q);

	cout << "入队列12345" << endl;
	EnQueue(Q, '1');
	EnQueue(Q, '2');
	EnQueue(Q, '3');
	EnQueue(Q, '4');
	EnQueue(Q, '5');
	DisplayQ(Q);
	cout << "此时栈满,执行入队列函数..." << endl;
	EnQueue(Q, 'x');
	cout << endl;
	return 0;
}
