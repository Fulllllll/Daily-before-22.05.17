#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;

template <class T>
class MyStack {
public:
	T* base;
	T* top;
	int sz;
	MyStack(int size);
	inline bool IsEmpty();
	inline bool Clear();
	T GetTop();
	bool Push(T e);
	bool Pop(T& e); //for <int> π”√
	bool Pop();

};
template<class T>
MyStack<T>::MyStack(int size)
{
	this->base = (T*)malloc(size * sizeof(T));
	if (!this->base)
	{
		cout << "’ª“Á≥ˆ" << endl;
		exit(-1);
	}
	this->top = this->base;
	this->sz = size;
}

template<class T>
bool MyStack<T>::IsEmpty()
{
	if (this->top == this->base) return true;
	else return false;
}

template<class T>
bool MyStack<T>::Clear()
{
	this->top = this->base;
	return true;
}

template<class T>
T MyStack<T>::GetTop()
{
	if (this->IsEmpty())
		return false;
	T e;
	e = *(this->top - 1);
	return e;
}

template<class T>
bool MyStack<T>::Push(T e)
{
	if (this->top - this->base >= this->sz)
	{
		exit(-1);
	}
	*(this->top++) = e;
	return true;
}

template<class T>
bool MyStack<T>::Pop(T& e)
{
	if (this->IsEmpty())
		return false;
	e = *(--(this->top));
	return true;
}

template<class T>
bool MyStack<T>::Pop()
{
	if (this->IsEmpty())
		return false;
	this->top--;
	return true;
}




