#include<iostream>
using namespace std;
#include"Cuboid.h"
#include"Cylinder.h"

int main()
{
	Base* p;
	Cuboid A(1, 2, 3);
	Cyclinder B(1, 10);
	p = &A;
	p->disp();
	p = &B;
	p->disp();
	return 0;
}