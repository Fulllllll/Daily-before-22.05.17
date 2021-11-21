#pragma once
#include"Time.h"
#include"Date.h"
#include<string>
class Birthtime :
	public Time, public Date
{
public:
	Birthtime(string name,int t1, int t2, int t3, int d1, int d2, int d3) :
		Time(t1, t2, t3), Date(d1, d2, d3)
	{
		Childname = name;
	}
	void display()
	{
		cout << "ÐÕÃû£º" << Childname << endl;
		Date::display();
		Time::display();
	}
protected:
	string Childname;

};