#include<bits/stdc++.h>
#include"MyStack.h"
using namespace std;

bool isoperator(char c);
int push_tnum_in_num(MyStack<int>& tnum);
bool judge(char o, char* p);		//判断是否能入栈一个符号
bool calculate();					//运算栈顶的一个符号
bool ispri(char c1, char c2);		//c1 优先级是否高于或等于 c2

char temp[100] = { 0 };
MyStack<int> num(100);
MyStack<char> opt(100);
int main()
{
	int count = 0;
	while ((temp[count++] = getchar()) != '\n') {}

	MyStack<int> tnum(5);

	for (int i = 0; i < count; i++)
	{
		if (isdigit(temp[i]))
			tnum.Push(temp[i] - '0');
		else if (isoperator(temp[i]))
		{
			push_tnum_in_num(tnum);
			tnum.Clear();

			if (judge(temp[i], &temp[i]))
				opt.Push(temp[i]);
		}
		else
		{
			cout << "表达式不合法\n";
			exit(-1);
		}
	}
	push_tnum_in_num(tnum);
	while (!opt.IsEmpty())
	{
		calculate();
	}
	cout << *(num.base) << endl;
}

bool isoperator(char c)
{
	if (c == '+' ||
		c == '-' ||
		c == '*' ||
		c == '/' ||
		c == '(' ||
		c == ')' ||
		c == '{' ||
		c == '}' ||
		c == '[' ||
		c == ']')
		return 1;
	else return 0;
}

bool ispri(char c1, char c2)
{
	if (c2 == '(' || c2 == '[' || c2 == '{')
		return 1;
	else if (c1 == '*' || c1 == '/')
		return 1;
	else if (c2 == '+' || c2 == '-')
		return 1;
	else return 0;
}
int push_tnum_in_num(MyStack<int>& tnum)
{
	if (tnum.IsEmpty()) return 2;
	else{
		int sum = 0;
		int count = 0;
		int t = 0;
		while (!tnum.IsEmpty())
		{
			tnum.Pop(t);
			sum += t * (pow(10, count++));
		}
		num.Push(sum);
		return 1;
	}
}


bool judge(char o, char* p)
{
	if (opt.IsEmpty())
		return 1;
	if (o == '(' || o == '{' || o == '[')
		return 1;
	else if (o == ')' || o == '}' || o == ']')
	{
		switch (o)
		{
		case ')':
			while ((!opt.IsEmpty()) && opt.GetTop() != '(')
			{
				calculate();
			}
			break;
		case ']':
			while ((!opt.IsEmpty()) && opt.GetTop() != '[')
			{
				calculate();
			}
			break;
		case '}':
			while ((!opt.IsEmpty()) && opt.GetTop() != '{')
			{
				calculate();
			}
			break;
		default:
			break;
		}
		if (opt.IsEmpty())
		{
			cout << "表达式不合法\n";
			exit(-1);
		}
		opt.Pop();
		return 0;
	}
	else
	{
		if(*(p-1) == '(' || *(p - 1) == '[' || *(p - 1) == '{' || *(p - 1) == '+' || *(p - 1) == '-' || *(p - 1) == '*' ||* (p - 1) == '/' ||
			*(p + 1) == ')' || *(p + 1) == ']' || *(p+ 1) == '}' || *(p + 1) == '+' || *(p + 1) == '-' || *(p + 1) == '*' || *(p + 1) == '/' )
		{
			cout << "表达式不合法\n";
			exit(-1);
		}
		while (!ispri(o, opt.GetTop()))
		{
			if (!opt.IsEmpty()) calculate();
			else break;
		}
		return 1;
	}
}
bool calculate()
{
	int e1 = 0, e2 = 0;
	num.Pop(e2);
	num.Pop(e1);
	char o;
	opt.Pop(o);
	switch (o)
	{
	case '+':
		num.Push(e1 + e2);
		break;
	case '-':
		num.Push(e1 - e2);
		break;
	case '*':
		num.Push(e1 * e2);
		break;
	case '/':
		if (e1 == 0)
		{
			cout << "表达式不合法\n";
			exit(-1);
		}
		num.Push(e1 / e2);
		break;
	default:
		cout << "表达式不合法\n";
		exit(-1);
	}
	return 1;
}
