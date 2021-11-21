#pragma once
#include "area_cl.h"
class Triangle :
    public area_cl
{
public:
    Triangle(double r, double s) :
        area_cl(r, s) {};
    virtual double area()
    {
        return height * width / 2.0;
    }
};
