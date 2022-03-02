#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Class.h"
#include"business.h"

void menu1();//主菜单
int menu2_find(FlightList* D);//查询业务
int menu3_booking(FlightList* D);//订票业务
int menu4_refund(FlightList* D);//退票业务

void menu1()//打印主菜单
{
	system("cls");
	printf("\n *************** ^@^欢迎使用航班票务系统***********\n");
	printf("\n                 * 1 查询业务 *\n");
	printf("                 * 2 订票业务 *\n");
	printf("                 * 3 退票业务 *\n");
	printf("                 * 0 退出票务系统 *\n");
	printf("\n ************** ^@^欢迎使用航班票务系统************\n");

	printf("\n请输入0-3 选择要进行的操作:\n");
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
	scanf_s("%s", endp);
	//功能函数
	query(flight, endp);
	menu1();
	return 1;
}

int menu3_booking(FlightList* flight)
{
	system("cls");
	char Fnumber[10];
	int Tnum;
	if (flight == NULL)
	{
		printf("\n\t系统错误\n\n");
		system("pause");
		return 0;
	}
	printf("\n请输入您需要预定的航班号：");
	scanf_s("%s", Fnumber);

	printf("\n请输入您需要预定的票数：");
	cin >> Tnum;
	//功能函数

	menu1();
	return 1;
}

int menu4_refund(FlightList* flight)
{
	system("cls");
	char Fnumber[10];
	char time[20];
	if (flight == NULL)
	{
		printf("\n\t系统错误\n\n");
		system("pause");
		return 0;
	}
	printf("\n请输入您需要退订的航班号：");
	scanf_s("%s", Fnumber);

	printf("\n请输入航票日期：");
	
	scanf_s("%s", time);

	//功能函数

	menu1();
}
