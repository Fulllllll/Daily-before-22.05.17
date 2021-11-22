#include<bits/stdc++.h>
#define MAX_SIZE 5
using namespace std;
typedef char ElemType;

//ջ 
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
		cout << "ջ��,popʧ��";
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

//����ջ��ɵĶ���  
typedef struct {
	Sqstack a;
	Sqstack b;
}Queue;

bool InitQueue(Queue& Q);
bool EnQueue(Queue& Q, ElemType x);
ElemType DeQueue(Queue& Q);
void DisplayQ(Queue& Q)
{
	cout << "���У�"<<endl;
	cout << "\tջa��"; 
	Display(Q.a);
	cout << endl<<"\tջb��";
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
	if (StackFull(Q.a) && !StackEmpty(Q.b))//��������ջa����ջb�ǿ�
	{
		cout << "������,���ʧ��";
		return 0;
	}
	if (!StackFull(Q.a))//����δ����ջaδ��
	{
		Push(Q.a, x);
		return 1;
	}
	if (StackFull(Q.a) && StackEmpty(Q.b))//����δ����ջaδ����ջbΪ��
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
		cout << "���п�,����ʧ��";
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
	cout << "��ʱջ��,ִ�г����к���..." << endl;
	DeQueue(Q);
	cout << endl << endl;

	cout << "�����abcde" << endl;
	EnQueue(Q, 'a');
	EnQueue(Q, 'b');
	EnQueue(Q, 'c'); 
	EnQueue(Q, 'd'); 
	EnQueue(Q, 'e'); 
	DisplayQ(Q);

	cout << "������:" << DeQueue(Q) << endl;
	DisplayQ(Q);

	cout << "�����12345" << endl;
	EnQueue(Q, '1');
	EnQueue(Q, '2');
	EnQueue(Q, '3');
	EnQueue(Q, '4');
	EnQueue(Q, '5');
	DisplayQ(Q);
	cout << "��ʱջ��,ִ������к���..." << endl;
	EnQueue(Q, 'x');
	cout << endl;
	return 0;
}
