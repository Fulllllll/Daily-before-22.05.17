#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXSIZE 10
typedef char Elemtype;

typedef struct {
	Elemtype* base;
	int front;
	int rear;
}SqQueue;

bool InitQueue(SqQueue& Q);
bool DestroyQueue(SqQueue& Q);
bool EnQueue(SqQueue& Q, Elemtype e);
void empty(SqQueue Q);
bool DeQueue(SqQueue& Q, Elemtype& e);
void display(SqQueue Q);




int main()
{
	SqQueue Q;
	InitQueue(Q);
	cout << "Ԫ�ؽ�����ing" << endl;
	EnQueue(Q, 'a'); EnQueue(Q, 'b'); EnQueue(Q, 'c');
	display(Q);
	empty(Q);

	Elemtype ch;
	cout << "������һ��Ԫ��,��Ԫ��Ϊ";
	DeQueue(Q,ch);
	cout << ch << endl;
	display(Q);

	cout << "Ԫ�ؽ�����ing" << endl;
	EnQueue(Q, 'd'); EnQueue(Q, 'e'); EnQueue(Q, 'f');
	display(Q);

	cout << "���γ���5��Ԫ��:";
	for (int i = 0; i < 5; i++)
	{
		DeQueue(Q, ch);
		cout << ch<<" ";
	}
	cout << endl;

	DestroyQueue(Q);
	return 0;
}

bool InitQueue(SqQueue& Q)
{
	Q.base = (Elemtype*)malloc(MAXSIZE * sizeof(Elemtype));
	if (!Q.base) exit(-1);
	Q.front = Q.rear = 0;
	return 1;
}
bool DestroyQueue(SqQueue& Q)
{
	cout << "�ͷŶ���ing";
	Q.front = 0;
	Q.rear = 0;
	free(Q.base);
	Q.base = NULL;
	return 1;
}
bool EnQueue(SqQueue& Q, Elemtype e)
{
	if (Q.rear + 1 % MAXSIZE == Q.front) 
	{
		cout << "������������ʧ��";
		exit(-1);
	}
	Q.base[Q.rear] = e;
	Q.rear = ((Q.rear + 1) % MAXSIZE);
}
void empty(SqQueue Q)
{
	if (Q.front == Q.rear)	cout << "����Ϊ��" << endl;
	else cout << "���зǿ�" << endl;
}

bool DeQueue(SqQueue& Q, Elemtype& e)
{
	if (Q.front == Q.rear)
	{
		cout << "������������ʧ��";
		exit(-1);
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return 1;
}

int  Queuelen(SqQueue Q)
{
	return (Q.rear + MAXSIZE - Q.front) % MAXSIZE;
}
void display(SqQueue Q)
{
	cout << "������Ϊ:";
	int len = Queuelen(Q);
	for (int i = 0; i < len; i++)
	{
		cout << Q.base[Q.front + i]<<" ";
	}
	cout << endl;
}
