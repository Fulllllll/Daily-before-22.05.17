#include"area_cl.h"
#include"Rectangle.h"
#include"Triangle.h"
#include<iostream>
using namespace std;
int main()
{
	area_cl* p;
	Rectangle A(10.0, 5.0);
	Triangle B(4.0, 6.0);
	p = &A;
	cout << p->area() << endl;
	p = &B;
	cout << p->area() << endl;
	return 0;
}