#include<stdio.h>
#include<iostream>
using namespace std;

#include"func.h"


int main()
{
	int map[ROW][COL] = { 0 };
	Init_Map(map);
	Show_Map(map);

	return 0;
}