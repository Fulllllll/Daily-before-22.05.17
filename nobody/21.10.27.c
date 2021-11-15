#define STACK_INIT_SIZE	100
#define STACK_INCREAMENT 10
#include <stdio.h>
#include <iostream>
using naemspace std;

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
bool Push(Sqstack& S);
bool Pop(Sqstack& S);


int main()
{
	Sqstack S;
	if (!Isempty) cout << "Õ»Îª¿Õ" << endl;

		return 0;
}

bool InitStack(Sqstack& S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S) exit(-1);
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
	Stacksize = 0;
	return 1;
}
bool Display(Sqstack S)
{
	for (int i = 0; i < S.stacksize; i++)
	{
		cout << *(S.base + i) << "  ";
	}
	return 1;
}

bool Isempty(Sqstack S)
{
	if (S.stacksize == 0)return 1;
	else return 0;
}
bool Push(Sqstack& S, SElemType e)
{
	if (S.top >= S.base + S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACK_INCREAMENT) * sizeof(SElemType));
		if (!S.base) exit(-1);
		S.top = S.base + S.stacksize;
		S.stacksize += STACK_INCREAMENT;
	}
	*(S.top++) = e;
	return 1;
}
bool Pop(Sqstack& S, SElemType& e)
{
	if (S.stacksize == 0)
	{
		cout << "Õ»¿Õ,popÊ§°Ü";
		exit(-1);
	}
	return 1;
}















