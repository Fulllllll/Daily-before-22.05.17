#pragma once
#include<iostream>
using namespace std;
class Time
{
public:
	Time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}
	void display()
	{
		cout << "����ʱ��:" << hours << "ʱ" << minutes << "��" << seconds << "��" << endl;
	}
protected:
	int hours, minutes, seconds;
};

