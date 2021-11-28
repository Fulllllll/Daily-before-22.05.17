#pragma once
#include"container.h"

class cube :
	public container {
public:
	cube(double bc) :container(bc) {};
	double S()
	{
		return 6 * radius * radius;
	}
	double V()
	{
		return  radius * radius * radius;
	}
};

