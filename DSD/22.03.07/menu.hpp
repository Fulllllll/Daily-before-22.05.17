#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Class.h"
#include"business.h"

void menu1();//主菜单
int menu2_find(FlightList* D);//查询业务
int menu3_booking(FlightList* flight, NormalOrderList* ODList);//订票业务
int menu4_refund(NormalOrderList* ODList, FlightList* flight);//退票业务

void menu1()//打印主菜单
{
	system("cls");
	printf("\n |**************  欢迎使用航班票务系统  ***********|");
	printf("\n |                  1 查询业务                     |");
	printf("\n |                  2 订票业务                     |");
	printf("\n |                  3 退票业务                     |");
	printf("\n |                  0 退出票务系统                 |");
	printf("\n |*************************************************|\n");
	printf(" 请输入要进行的操作:");
}

int menu2_find(FlightList* flight)
{
	system("cls");
	char endp[10] = { 0 };
	if (flight == NULL)
	{
		printf("\n\t系统错误\n\n");
		system("pause");
		return 0;
	}
	printf("请输入您要去往的终点站:");
	scanf("%s", endp);
	//功能函数
	query(flight, endp);
	system("pause");
	menu1();
	return 1;
}

int menu3_booking(FlightList* flight, NormalOrderList* ODList)
{
	system("cls");
	char Fnumber[10] = { '0' };
	int Tnum;
	char t;
	if (flight == NULL)
	{
		printf("\n\t系统错误\n\n");
		system("pause");
		return 0;
	}
	printf("\n请输入您需要预定的航班号：");
	scanf("%s", Fnumber);

	printf("\n请输入您需要预定的票数：");
	cin >> Tnum;

	//功能函数
	booking(flight, ODList, Fnumber, Tnum);
	menu1();
	return 1;
}


int menu4_refund(NormalOrderList* ODList, FlightList* flight)
{
	system("cls");

	//功能函数
	refund(ODList, flight);
	menu1();
	return 1;
}
