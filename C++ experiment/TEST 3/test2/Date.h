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
		cout << "出生年月：" << year << "年" << month << "月" << day << "日" << endl;
	}
protected:
	int month, day, year;
};