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
	cout << "姓名：" << name << endl;
	cout << "出生日期：";
	birthday.display();
	cout << "性别：" << sex << endl;
}
