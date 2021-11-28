#include<iostream>
using namespace std;

#include"cube.h"
#include"cylinder.h"
#include"sphere.h"
int main()
{
	container* p;
	cube A(5.0);
	sphere B(5.0);
	cylinder C(5.0, 6.0);
	p = &A;
	cout << "正方体\n表面积：" << p->S() << endl;
	cout << "体积：" << p->V() << endl<<endl;
	p = &B;
	cout << "球体\n表面积：" << p->S() << endl;
	cout << "体积：" << p->V() << endl << endl;
	p = &C;
	cout << "圆柱体\n表面积：" << p->S() << endl;
	cout << "体积：" << p->V() << endl << endl;
	return 0;
}