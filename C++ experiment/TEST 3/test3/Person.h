#pragma once
#include"Date.h"
#include<iostream>
#include<string>
using namespace std;
class Person {
public:
	Person(string _name, int m, int d, int y, string _sex);
	void show();
protected:
	string name;
	Date birthday;
	string sex;
};
