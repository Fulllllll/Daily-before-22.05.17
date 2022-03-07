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
			cout << "����ţ�" << temp->flightnum << endl;
			cout << "�������ڣ�" << temp->time << endl;
			cout << "�ɻ��ͺţ�" << temp->model << endl;
			cout << "A����������" << temp->A << endl;
			cout << "B����������" << temp->B << endl;
			cout << "C����������" << temp->C << endl;
			cout << endl;

		}
	}
	if (flag == 0)
		cout << "���಻����\n" << endl;
}




bool refund(NormalOrderList* ODList, FlightList* flight)
{
	char name[10];
	char flightnum[10];
	cout << "������������";
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
		printf("û�в�ѯ����Ʊ�ɹ���Ϣ\n");
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
	
	//ɾ������
	for (int k = i + 1; k < ODList->sz; k++)
	{
		ODList->List[k - 1] = ODList->List[k];
	}
	ODList->sz--;
	cout << "��Ʊ�ɹ�\n";
	//���º򲹶���
	Ordernode next_waiting_one;
	plane& tempplane = flight->List[j];
	if (tempplane.WaitList->next != NULL)
		next_waiting_one = tempplane.WaitList->next->order;

	while (tempplane.WaitList->next != NULL && tempplane.A >= next_waiting_one.A && tempplane.B >= next_waiting_one.B && tempplane.C >= next_waiting_one.C)
	{

		tempplane.A -= next_waiting_one.A;
		tempplane.B -= next_waiting_one.B;
		tempplane.C -= next_waiting_one.C;

		//�򲹱�����
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
	cout << "����������Ҫ�ĸ����ȼ���Ʊ��" << endl;
	cout << "A��Ʊ:"; cin >> a;
	cout << "B��Ʊ:"; cin >> b;
	cout << "C��Ʊ:"; cin >> c;

	while (count != 0)
	{
		temp = &(flight->List[flight->sz - count--]);
		if (strcmp(q, temp->flightnum) == 0)
		{
			flag = 1;
			if ((a <= temp->A) && (b <= temp->B) && (c <= temp->C))
			{
				strcpy(ODList->List[ODList->sz].flightnum, Ft);
				printf("�������������:");
				cin >> ODList->List[ODList->sz].name;
				ODList->List[ODList->sz].A = a; ODList->List[ODList->sz].B = b; ODList->List[ODList->sz].C = c;
				ODList->sz++;
				cout << "Ԥ���ɹ�!" << endl;
				cout << "�����λ��:";
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
				cout << "�޿�����λ" << endl;
				cout << "��ѡ�����²�����" << endl;
				cout << "1.��������� 2.�ص���ʼ����" << endl;
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
					cout << "������������֣�" << endl;
					cin >> q->order.name;
					strcpy(q->order.flightnum, Ft);
					q->order.A = a; q->order.B = b;  q->order.C = c;
					p->next = q;
					q->next = NULL;
					cout << "�Ѽ����������" << endl;
					system("pause");
				}
			}
		}
	}
	if (flag == 0)
	{
		cout << "�ú��಻���ڣ�" << endl;
		system("pause");
	}
}