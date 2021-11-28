#pragma once

#include<iostream>
using namespace std;
class container {
protected:
	double radius;
public:
	container(double r)
	{
		radius = r;
	}
	virtual double S() = 0;
	virtual double V() = 0;
};