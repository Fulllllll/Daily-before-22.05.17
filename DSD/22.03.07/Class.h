#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<bits/stdc++.h>
using namespace std;

#define BASIC_capacity1 20
#define BASIC_capacity2 20

struct Ordernode {		//订单结点
	char name[20];
	char flightnum[10];
	int A;
	int B;
	int C;
};

struct NormalOrderList { //正常订单顺序表
	Ordernode* List;
	int sz;
	int capacity;
};

typedef struct Waitnode {	//候补订单链表结点
	Ordernode order;
	Waitnode* next = NULL;
}*Waitlist;


struct plane {			//plane，是航班数组的结点
	char flightnum[10];
	char dest[10];
	char time[20];
	char model[10];
	int A, B, C;
	Waitlist WaitList;			//带头结点的候补名单链表
};

struct FlightList {			//航班数组
	plane* List;
	int sz;
	int capacity;
};

bool InitFlightList(FlightList* flight);//初始化航班表
bool LoadFlightList(FlightList* flight);//从文件加载航班表
bool SaveFlightList(FlightList* flight);//保存航班表到文件
bool DelFlightList(FlightList* flight);//销毁航班表

bool InitOrders(NormalOrderList* ODList, FlightList* flight);//初始化订单表和候补表
bool LoadOrders(NormalOrderList* ODList, FlightList* flight);//从文件加载订单表和候补表
bool SaveOrders(NormalOrderList* ODList, FlightList* flight);//保存订单表和候补表到文件
bool DelOrders(NormalOrderList* ODList, FlightList* flight);//销毁订单表和候补表