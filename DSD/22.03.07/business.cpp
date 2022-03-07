#include"business.h"


void query(FlightList* flight, char* t)
{
	char* q = t;
	plane* temp = NULL;
	int flag = 0;
	int count = flight->sz;
	while (count != 0)
	{
		temp = &(flight->List[flight->sz - count--]);
		if (strcmp(q, temp->dest) == 0)
		{
			flag = 1;
			cout << "航班号：" << temp->flightnum << endl;
			cout << "飞行日期：" << temp->time << endl;
			cout << "飞机型号：" << temp->model << endl;
			cout << "A等座数量：" << temp->A << endl;
			cout << "B等座数量：" << temp->B << endl;
			cout << "C等座数量：" << temp->C << endl;
			cout << endl;

		}
	}
	if (flag == 0)
		cout << "航班不存在\n" << endl;
}




bool refund(NormalOrderList* ODList, FlightList* flight)
{
	char name[10];
	char flightnum[10];
	cout << "请输入姓名：";
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ODList->sz; i++)
	{
		if (strcmp(ODList->List[i].name, name) == 0)
		{
			strcpy(flightnum, ODList->List[i].flightnum);
			break;
		}			
	}

	if (i >= ODList->sz)
	{
		printf("没有查询到订票成功信息\n");
		system("pause");
		return 0;
	}
	

	int j = 0;
	for (j = 0; j < flight->sz; j++)
	{
		if (strcmp(flightnum, flight->List[j].flightnum) == 0)
		{
			flight->List[j].A += ODList->List[i].A;
			flight->List[j].B += ODList->List[i].B;
			flight->List[j].C += ODList->List[i].C;
			break;
		}
	}
	
	//删除订单
	for (int k = i + 1; k < ODList->sz; k++)
	{
		ODList->List[k - 1] = ODList->List[k];
	}
	ODList->sz--;
	cout << "退票成功\n";
	//更新候补订单
	Ordernode next_waiting_one;
	plane& tempplane = flight->List[j];
	if (tempplane.WaitList->next != NULL)
		next_waiting_one = tempplane.WaitList->next->order;

	while (tempplane.WaitList->next != NULL && tempplane.A >= next_waiting_one.A && tempplane.B >= next_waiting_one.B && tempplane.C >= next_waiting_one.C)
	{

		tempplane.A -= next_waiting_one.A;
		tempplane.B -= next_waiting_one.B;
		tempplane.C -= next_waiting_one.C;

		//候补变正常
		strcpy(ODList->List[ODList->sz].flightnum, tempplane.flightnum);
		strcpy(ODList->List[ODList->sz].name, next_waiting_one.name);
		ODList->List[ODList->sz].A = next_waiting_one.A;
		ODList->List[ODList->sz].B = next_waiting_one.B;
		ODList->List[ODList->sz++].C = next_waiting_one.C;
		
		Waitnode* temp = tempplane.WaitList->next;
		tempplane.WaitList->next = temp->next;
		free(temp);
		temp = NULL;
		if (tempplane.WaitList->next != NULL)
			next_waiting_one = tempplane.WaitList->next->order;
	}
	system("pause");
	return 1;
}


void booking(FlightList* flight, NormalOrderList* ODList, char* Ft, int tnum)
{
	char* q = Ft;
	int flag = 0;
	plane* temp = NULL;
	int count = flight->sz;

	int a, b, c;
	cout << "请输入你需要的各个等级的票数" << endl;
	cout << "A等票:"; cin >> a;
	cout << "B等票:"; cin >> b;
	cout << "C等票:"; cin >> c;

	while (count != 0)
	{
		temp = &(flight->List[flight->sz - count--]);
		if (strcmp(q, temp->flightnum) == 0)
		{
			flag = 1;
			if ((a <= temp->A) && (b <= temp->B) && (c <= temp->C))
			{
				strcpy(ODList->List[ODList->sz].flightnum, Ft);
				printf("请输入你的名字:");
				cin >> ODList->List[ODList->sz].name;
				ODList->List[ODList->sz].A = a; ODList->List[ODList->sz].B = b; ODList->List[ODList->sz].C = c;
				ODList->sz++;
				cout << "预定成功!" << endl;
				cout << "你的座位号:";
				for (int i = 0; i < a; i++)
				{
					if (a == 0) break;
					cout << "A" << temp->A - i << " ";
				}
				for (int i = 0; i < b; i++)
				{
					if (b == 0) break;
					cout << "B" << temp->B - i << " ";
				}
				for (int i = 0; i < c; i++)
				{
					if (c == 0) break;
					cout << "C" << temp->C - i << " ";
				}
				temp->A -= a;
				temp->B -= b;
				temp->C -= c;
				system("pause");
			}
			else
			{
				cout << "无空闲座位" << endl;
				cout << "请选择以下操作：" << endl;
				cout << "1.进入候补名单 2.回到初始界面" << endl;
				int t;
				cin >> t;
				if (t == 1)
				{

					int i = 0;
					Waitlist p = temp->WaitList;
					while (p->next)
					{
						p = p->next;
					}
					Waitlist q = (Waitnode*)malloc(sizeof(Waitnode));
					cout << "请输入你的名字：" << endl;
					cin >> q->order.name;
					strcpy(q->order.flightnum, Ft);
					q->order.A = a; q->order.B = b;  q->order.C = c;
					p->next = q;
					q->next = NULL;
					cout << "已加入候补名单！" << endl;
					system("pause");
				}
			}
		}
	}
	if (flag == 0)
	{
		cout << "该航班不存在！" << endl;
		system("pause");
	}
}