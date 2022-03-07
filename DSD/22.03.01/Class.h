#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<bits/stdc++.h>
using namespace std;

#define BASIC_capacity1 5
#define BASIC_capacity2 10

struct Ordernode {
	char name[20];
	char flightnum[10];
	int A;
	int B;
	int C;
};

struct NormalOrderList {
	Ordernode* List;
	int sz;
	int capacity;
};

typedef struct Waitnode {	//候补订单结点
	Ordernode order;
	Waitnode* next = NULL;
}*Waitlist;


struct plane {			//plane，是航班数组的结点
	char flightnum[10];
	char dest[10];
	char time[20];
	char model[10];
	int A, B, C;
	Waitlist Lhead;			//带头结点的候补名单链表
};

struct FlightList {			//航班数组
	plane* List;
	int sz;
	int capacity;
};

bool InitFlightList(FlightList* flight);
bool LoadFlightList(FlightList* flight);
bool SaveFlightList(FlightList* flight);
bool DelFlightList(FlightList* flight);

bool InitOrders(NormalOrderList* ODList, FlightList* flight);
bool LoadOrders(NormalOrderList* ODList, FlightList* flight);
bool SaveOrders(NormalOrderList* ODList, FlightList* flight);
bool DelOrders(NormalOrderList* ODList, FlightList* flight);