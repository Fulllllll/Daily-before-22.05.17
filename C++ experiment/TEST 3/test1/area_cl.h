#pragma once
class area_cl
{
protected:
	double height;
	double width;
public:
	area_cl(double r, double s)
	{
		height = r;
		width = s;
	}
	virtual double area() = 0;
};

