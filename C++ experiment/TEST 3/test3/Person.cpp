#include"person.h"
#include<iostream>
using namespace std;
Person::Person(string _name, int m, int d, int y, string _sex):
	birthday(m,d,y)
{
	name = _name;
	sex = _sex;
}
void Person::show()
{
	cout << "������" << name << endl;
	cout << "�������ڣ�";
	birthday.display();
	cout << "�Ա�" << sex << endl;
}
