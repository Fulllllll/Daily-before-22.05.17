#pragma once
#include"container.h"
class sphere :
	public container {
public:
	sphere(double _r) :container(_r) {};
	double S()
	{
		return 4 * radius * radius * 3.1415;
	}
	double V()
	{
		return  3.1415 * radius * radius * radius * 4 / 3;
	}
};
