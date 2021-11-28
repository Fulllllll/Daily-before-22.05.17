#pragma once
class Base
{
protected:
	double h;
public:
	Base() {};
	Base(double _h) { h = _h; };
	virtual void disp() = 0;
};

