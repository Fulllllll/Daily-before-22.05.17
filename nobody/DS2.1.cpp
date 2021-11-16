#define STACK_INIT_SIZE	100
#define STACK_INCREAMENT 10
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char SElemType;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}Sqstack;

bool InitStack(Sqstack& S);
bool DestroyStack(Sqstack& S);
bool Display(Sqstack S);
bool Isempty(Sqstack S);
bool Push(Sqstack& S, SElemType e);
bool Pop(Sqstack& S, SElemType& e);


int main()
{
	Sqstack S;
	InitStack(S);
	if (Isempty(S)) cout << "Õ»Îª¿Õ" << endl;
	else cout << "Õ»·Ç¿Õ" << endl;
	Push(S, 'a'); Push(S, 'b'); 
	Push(S, 'c'); Push(S, 'd'); Push(S, 'e');
	cout << "ÒÀ´ÎÈëÕ»a,b,c,d,e"<<endl;
	Display(S);
	if (Isempty(S)) cout << "Õ»Îª¿Õ" << endl;
	else cout << "Õ»·Ç¿Õ" << endl;

	char e;
	cout << "³öÕ»ÐòÁÐÎª£º";
	for (int i = 0; i < 5; i++)
	{
		Pop(S, e);
		cout << e;
	}
	cout << endl;
	if (Isempty(S)) cout << "Õ»Îª¿Õ" << endl;
	else cout << "Õ»·Ç¿Õ" << endl;
	DestroyStack(S);
	return 0;
}

bool InitStack(Sqstack& S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) exit(-1);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return 1;
}
bool DestroyStack(Sqstack& S)
{
	S.base = NULL;
	S.top = NULL;
	free(S.top);
	free(S.base);
	S.stacksize = 0;
	return 1;
}
bool Display(Sqstack S)
{
	cout << "Õ»ÄÚÎª£º";
	SElemType* p = S.base;
	while (p != S.top)
	{
		cout << *(p++) << " ";
	}
	return 1;
}

bool Isempty(Sqstack S)
{
	return (S.top-S.base==0);
//	int i = 0;
//	SElemType* p = S.base;
//	while (p != S.top)
//	{
//		p++;
//		i++;
//	}
//	return i;
}
bool Push(Sqstack& S, SElemType e)
{
	if (S.top >= S.base + S.stacksize)
	{
		SElemType* p = NULL;
		p = (SElemType*)realloc(S.base, (S.stacksize + STACK_INCREAMENT) * sizeof(SElemType));
		if (!p) exit(-1);
		S.base = p;
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREAMENT;
	}
	*(S.top++) = e;
	return 1;
}
bool Pop(Sqstack& S, SElemType& e)
{
	if (S.base==S.top)
	{
		cout << "Õ»¿Õ,popÊ§°Ü";
		exit(-1);
	}
	e = *(--S.top);
	S.stacksize--;
	return 1;
}







