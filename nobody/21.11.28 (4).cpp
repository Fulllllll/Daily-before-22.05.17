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
	cout << "������\n�������" << p->S() << endl;
	cout << "�����" << p->V() << endl<<endl;
	p = &B;
	cout << "����\n�������" << p->S() << endl;
	cout << "�����" << p->V() << endl << endl;
	p = &C;
	cout << "Բ����\n�������" << p->S() << endl;
	cout << "�����" << p->V() << endl << endl;
	return 0;
}