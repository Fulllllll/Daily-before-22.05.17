#include"Staff.h"

Staff::Staff(string _name, int m, int d, int y, string _sex,
	string _depar, string _pos, int _salary) :
	Person(_name, m, d, y, _sex)
{
	department = _depar;
	position = _pos;
	salary = _salary;
}
void Staff::show()
{
	Person::show();
	cout << "�������ţ�" << department << endl;
	cout << "ְ��" << position << endl;
	cout << "���ʣ�" << salary << endl;
}