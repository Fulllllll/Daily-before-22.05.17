#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include"Class.h"
#include"business.h"

void menu1();//���˵�
int menu2_find(FlightList* D);//��ѯҵ��
int menu3_booking(FlightList* D);//��Ʊҵ��
int menu4_refund(FlightList* D);//��Ʊҵ��

void menu1()//��ӡ���˵�
{
	system("cls");
	printf("\n *************** ^@^��ӭʹ�ú���Ʊ��ϵͳ***********\n");
	printf("\n                 * 1 ��ѯҵ�� *\n");
	printf("                 * 2 ��Ʊҵ�� *\n");
	printf("                 * 3 ��Ʊҵ�� *\n");
	printf("                 * 0 �˳�Ʊ��ϵͳ *\n");
	printf("\n ************** ^@^��ӭʹ�ú���Ʊ��ϵͳ************\n");

	printf("\n������0-3 ѡ��Ҫ���еĲ���:\n");
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
	scanf_s("%s", endp);
	//���ܺ���
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
		printf("\n\tϵͳ����\n\n");
		system("pause");
		return 0;
	}
	printf("\n����������ҪԤ���ĺ���ţ�");
	scanf_s("%s", Fnumber);

	printf("\n����������ҪԤ����Ʊ����");
	cin >> Tnum;
	//���ܺ���

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
		printf("\n\tϵͳ����\n\n");
		system("pause");
		return 0;
	}
	printf("\n����������Ҫ�˶��ĺ���ţ�");
	scanf_s("%s", Fnumber);

	printf("\n�����뺽Ʊ���ڣ�");
	
	scanf_s("%s", time);

	//���ܺ���

	menu1();
}
