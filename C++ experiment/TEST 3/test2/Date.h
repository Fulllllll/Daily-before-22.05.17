#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int m, int d, int y)
	{
		month = m;
		day = d;
		year = y;
	}
	void display()
	{
		cout << "�������£�" << year << "��" << month << "��" << day << "��" << endl;
	}
protected:
	int month, day, year;
};