#pragma once
#include"container.h"

class cylinder :
	public container {
private:
	double h;
public:
	cylinder(double r,double _h) :container(r)
	{
		h = _h;
	}
	double S()
	{
		return radius * radius * 3.1415 * 2 + 2 * 3.1415 * radius*h;
	}
	double V()
	{
		return  radius * radius * 3.1415 * h;
	}
};