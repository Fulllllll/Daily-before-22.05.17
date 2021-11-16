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
	cout << "元素进队列ing" << endl;
	EnQueue(Q, 'a'); EnQueue(Q, 'b'); EnQueue(Q, 'c');
	display(Q);
	empty(Q);

	Elemtype ch;
	cout << "出队列一个元素,该元素为";
	DeQueue(Q,ch);
	cout << ch << endl;
	display(Q);

	cout << "元素进队列ing" << endl;
	EnQueue(Q, 'd'); EnQueue(Q, 'e'); EnQueue(Q, 'f');
	display(Q);

	cout << "依次出队5个元素:";
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
	cout << "释放队列ing";
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
		cout << "队列满，操作失败";
		exit(-1);
	}
	Q.base[Q.rear] = e;
	Q.rear = ((Q.rear + 1) % MAXSIZE);
}
void empty(SqQueue Q)
{
	if (Q.front == Q.rear)	cout << "队列为空" << endl;
	else cout << "队列非空" << endl;
}

bool DeQueue(SqQueue& Q, Elemtype& e)
{
	if (Q.front == Q.rear)
	{
		cout << "队列满，操作失败";
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
	cout << "队列内为:";
	int len = Queuelen(Q);
	for (int i = 0; i < len; i++)
	{
		cout << Q.base[Q.front + i]<<" ";
	}
	cout << endl;
}
