#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<bits/stdc++.h>
using namespace std;

#define BASIC_capacity1 20
#define BASIC_capacity2 20

struct Ordernode {		//�������
	char name[20];
	char flightnum[10];
	int A;
	int B;
	int C;
};

struct NormalOrderList { //��������˳���
	Ordernode* List;
	int sz;
	int capacity;
};

typedef struct Waitnode {	//�򲹶���������
	Ordernode order;
	Waitnode* next = NULL;
}*Waitlist;


struct plane {			//plane���Ǻ�������Ľ��
	char flightnum[10];
	char dest[10];
	char time[20];
	char model[10];
	int A, B, C;
	Waitlist WaitList;			//��ͷ���ĺ���������
};

struct FlightList {			//��������
	plane* List;
	int sz;
	int capacity;
};

bool InitFlightList(FlightList* flight);//��ʼ�������
bool LoadFlightList(FlightList* flight);//���ļ����غ����
bool SaveFlightList(FlightList* flight);//���溽����ļ�
bool DelFlightList(FlightList* flight);//���ٺ����

bool InitOrders(NormalOrderList* ODList, FlightList* flight);//��ʼ��������ͺ򲹱�
bool LoadOrders(NormalOrderList* ODList, FlightList* flight);//���ļ����ض�����ͺ򲹱�
bool SaveOrders(NormalOrderList* ODList, FlightList* flight);//���涩����ͺ򲹱��ļ�
bool DelOrders(NormalOrderList* ODList, FlightList* flight);//���ٶ�����ͺ򲹱�