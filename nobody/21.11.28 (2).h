#pragma once
#include<iostream>
using namespace std;
#include"Base.h"
#include"Cuboid.h"
#include"Cylinder.h"
class Cuboid :
	public Base{
private:
	double l, w;
public:
	Cuboid(double _l, double _w, double _h) :Base(_h)
	{
		l = _l;
		w = _w;
	}
	void disp()
	{
		cout << "���������Ϊ��" << l * h * w << endl;
	}
};

