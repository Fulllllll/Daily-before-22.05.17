#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;

#include"menu.cpp"
#include"Class.h"
#include"business.h"

void show1(FlightList* flight)
{
	cout << flight->List[0].flightnum << endl;
	cout << flight->List[0].dest << endl;
	cout << flight->List[0].time << endl;
	cout << flight->List[0].model << endl;
	cout << flight->List[0].A << endl;
	cout << flight->List[0].B << endl;
	cout << flight->List[0].C << endl << endl;

	cout << flight->List[1].flightnum << endl;
	cout << flight->List[1].dest << endl;
	cout << flight->List[1].time << endl;
	cout << flight->List[1].model << endl;
	cout << flight->List[1].A << endl;
	cout << flight->List[1].B << endl;
	cout << flight->List[1].C << endl;
	cout << endl << endl << endl;
}
void show2(NormalOrderList* ODList)
{
	cout << ODList->List[0].flightnum << endl;
	cout << ODList->List[1].flightnum << endl;
	cout << ODList->List[2].flightnum << endl;
	cout << endl << endl << endl;
}
void show3(FlightList* flight)
{
	for (int i = 0; i < flight->sz; i++)
	{
		Waitlist p = flight->List[i].Lhead->next;
		while (p)
		{
			cout << p->order.name << endl;
			p = p->next;
		}
	}
	cout << endl << endl << endl;
}
//show1(&flight);
//show2(&ODList);
//show3(&flight);

int main()
{
	FlightList flight;
	InitFlightList(&flight);
	NormalOrderList ODList;
	InitOrders(&ODList, &flight);
	menu1();
	int menu;
	while (scanf("%d", &menu))
	{
		switch (menu)
		{
		case 1:menu2_find(&flight); break;
		case 2:menu3_booking(&flight); break;
		case 3:menu4_refund(&flight); break;
		case 0:exit(0); break;
		}
	}
	SaveFlightList(&flight);
	SaveOrders(&ODList, &flight);
	DelOrders(&ODList, &flight);
	DelFlightList(&flight);
	return 0;
}