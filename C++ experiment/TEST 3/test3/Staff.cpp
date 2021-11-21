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
	cout << "工作部门：" << department << endl;
	cout << "职务：" << position << endl;
	cout << "工资：" << salary << endl;
}