#pragma once
#include<iostream>
using namespace std;
#include"Base.h"

class Cyclinder :
	public Base {
protected:
	double r;
public:
	Cyclinder(double _r, double _h) :Base(_h)
	{
		r = _r;
	}
	void disp()
	{
		cout << "Բ�������Ϊ��" << r * r * 3.1415 * h << endl;
	}
};