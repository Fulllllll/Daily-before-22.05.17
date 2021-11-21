#pragma once
#pragma once
#include"Date.h"
#include"person.h"

class Staff :
	public Person
{
public:
	Staff(string _name, int m, int d, int y, string _sex, 
			string _depar, string _pos, int _salary);
	void show();
protected:
	string department;
	string position;
	int salary;
};