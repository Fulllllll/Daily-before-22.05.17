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
		cout << "出生时间:" << hours << "时" << minutes << "分" << seconds << "秒" << endl;
	}
protected:
	int hours, minutes, seconds;
};

