#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Class.h"
#include"business.h"

void menu1();//���˵�
int menu2_find(FlightList* D);//��ѯҵ��
int menu3_booking(FlightList* flight, NormalOrderList* ODList);//��Ʊҵ��
int menu4_refund(NormalOrderList* ODList, FlightList* flight);//��Ʊҵ��

void menu1()//��ӡ���˵�
{
	system("cls");
	printf("\n |**************  ��ӭʹ�ú���Ʊ��ϵͳ  ***********|");
	printf("\n |                  1 ��ѯҵ��                     |");
	printf("\n |                  2 ��Ʊҵ��                     |");
	printf("\n |                  3 ��Ʊҵ��                     |");
	printf("\n |                  0 �˳�Ʊ��ϵͳ                 |");
	printf("\n |*************************************************|\n");
	printf(" ������Ҫ���еĲ���:");
}

int menu2_find(FlightList* flight)
{
	system("cls");
	char endp[10] = { 0 };
	if (flight == NULL)
	{
		printf("\n\tϵͳ����\n\n");
		system("pause");
		return 0;
	}
	printf("��������Ҫȥ�����յ�վ:");
	scanf("%s", endp);
	//���ܺ���
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
		printf("\n\tϵͳ����\n\n");
		system("pause");
		return 0;
	}
	printf("\n����������ҪԤ���ĺ���ţ�");
	scanf("%s", Fnumber);

	printf("\n����������ҪԤ����Ʊ����");
	cin >> Tnum;

	//���ܺ���
	booking(flight, ODList, Fnumber, Tnum);
	menu1();
	return 1;
}


int menu4_refund(NormalOrderList* ODList, FlightList* flight)
{
	system("cls");

	//���ܺ���
	refund(ODList, flight);
	menu1();
	return 1;
}
