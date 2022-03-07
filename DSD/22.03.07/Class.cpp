#include"Class.h"

bool InitFlightList(FlightList* flight)
{
	flight->List = (plane*) malloc(BASIC_capacity1 * sizeof(plane));
	if (!flight->List)
	{
		cout << strerror(errno) << endl;
		exit(0);
	}
	flight->sz = 0;
	flight->capacity = BASIC_capacity1;
	LoadFlightList(flight);
	return 1;
}
bool InitOrders(NormalOrderList* ODList, FlightList* flight)
{
	ODList->List = (Ordernode*)malloc(BASIC_capacity2 * sizeof(Ordernode));
	if (!ODList->List)
	{
		cout << strerror(errno) << endl;
		exit(0);
	}
	ODList->sz = 0;
	ODList->capacity = BASIC_capacity2;
	LoadOrders(ODList, flight);
	return 1;
}

bool LoadFlightList(FlightList* flight)
{
	plane* temp = NULL;
	char buf[15] = { 0 };

	FILE* fp = fopen("flight.txt", "r");
	if (!fp)
	{
		cout << strerror(errno) << endl;
		exit(0);
	}
	fscanf(fp, "%s\n", buf);
	while (strcmp(buf, "�ɻ�") == 0 && (!feof(fp)))
	{
		//	
		// ��̬��������
		//
		temp = &(flight->List[flight->sz++]);
		fscanf(fp, "�����:%s ", temp->flightnum);
		fscanf(fp, "����վ:%s ", temp->dest);
		fscanf(fp, "���ʱ��:%s ", temp->time);
		fscanf(fp, "����:%s\n", temp->model);
		fscanf(fp, "Ʊ����Ϣ\n A:%d B:%d C:%d\n", &(temp->A), &(temp->B), &(temp->C));
		temp->WaitList = (Waitnode*)malloc(sizeof(Waitnode));
		temp->WaitList->next = NULL;
		fscanf(fp, "%s\n", buf);
	}
	fclose(fp);
	return 1;
}

bool LoadOrders(NormalOrderList* ODList, FlightList* flight)
{
	Ordernode* temp = NULL;
	int flag = 0;
	FILE* fp = fopen("order.txt", "r");
	if (!fp)
	{
		cout << strerror(errno) << endl;
		exit(0);
	}

	while (fscanf(fp, "%d\n", &flag) && (!feof(fp)))
	{
		if (flag == 0)
		{
			if (ODList->sz >= ODList->capacity)
			{
				//aaaaaaaaa
			}
			fscanf(fp, "�����:%s ", ODList->List[ODList->sz].flightnum);
			fscanf(fp, "����:%s ", ODList->List[ODList->sz].name);
			fscanf(fp, "A:%d ", &(ODList->List[ODList->sz].A));
			fscanf(fp, "B:%d ", &(ODList->List[ODList->sz].B));
			fscanf(fp, "C:%d\n", &(ODList->List[ODList->sz++].C));
		}
		else if (flag == 1)
		{
			//AddWaitList;
			char planename[10] = { 0 };
			fscanf(fp, "�����:%s ", planename);
			int i = 0;
			for (i = 0; i < flight->sz; i++)
			{
				if (strcmp(planename, flight->List[i].flightnum) == 0)
				{
					
					break;
				}
			}

			Waitlist tail = flight->List[i].WaitList;
			while (tail->next != NULL) tail = tail->next;

			Waitnode* p = (Waitnode*)malloc(sizeof(Waitnode));
			strcpy(p->order.flightnum, planename);
			fscanf(fp, "����:%s ", p->order.name);
			fscanf(fp, "A:%d ", &(p->order.A));
			fscanf(fp, "B:%d ", &(p->order.B));
			fscanf(fp, "C:%d\n", &(p->order.C));

			p->next = tail->next;
			tail->next = p;
			
		}
		else { ; }
	}
	return 1;
}

bool SaveFlightList(FlightList* flight)
{
	remove("flight.txt");
	plane* temp = NULL;
	int count = flight->sz;
	FILE* fp = fopen("flight.txt", "w");
	if (!fp)
	{
		cout << strerror(errno) << endl;
		exit(0);
	}
	while(count != 0)
	{
		temp = &(flight->List[flight->sz - count--]);
		fprintf(fp, "�ɻ�\n");
		fprintf(fp, "�����:%s ", temp->flightnum);
		fprintf(fp, "����վ:%s ", temp->dest);
		fprintf(fp, "���ʱ��:%s ", temp->time);
		fprintf(fp, "����:%s\n", temp->model);
		fprintf(fp, "Ʊ����Ϣ\n A:%d B:%d C:%d\n", temp->A, temp->B, temp->C);
	}
	fclose(fp);
	return 1;
}

bool SaveOrders(NormalOrderList* ODList, FlightList* flight)
{
	remove("order.txt");
	FILE* fp = fopen("order.txt", "w");
	if (!fp)
	{
		cout << strerror(errno) << endl;
		exit(0);
	}
	for (int i = 0; i < ODList->sz; i++)   //������������
	{	
		fprintf(fp, "0 ");
		fprintf(fp, "�����:%s ", ODList->List[i].flightnum);
		fprintf(fp, "����:%s ", ODList->List[i].name);
		fprintf(fp, "A:%d ", ODList->List[i].A);
		fprintf(fp, "B:%d ", ODList->List[i].B);
		fprintf(fp, "C:%d\n", ODList->List[i].C);
	}
	for (int i = 0; i < flight->sz; i++)	//����󲹶���
	{
		Waitlist p = flight->List[i].WaitList->next;
		while (p)
		{
			fprintf(fp, "1 ");
			fprintf(fp, "�����:%s ", p->order.flightnum);
			fprintf(fp, "����:%s ", p->order.name);
			fprintf(fp, "A:%d ", p->order.A);
			fprintf(fp, "B:%d ", p->order.B);
			fprintf(fp, "C:%d\n", p->order.C);
			p = p->next;
		}
	}

	fclose(fp);
	return 1;
}
bool DelOrders(NormalOrderList* ODList, FlightList* flight)
{
	//�ͷ����������ռ�
	free(ODList->List);
	ODList->List = NULL;
	ODList->capacity = 0;
	ODList->sz = 0;
	//�ͷź򲹶����ռ�
	for (int i = 0; i < flight->sz; i++)	
	{
		Waitlist p = flight->List[i].WaitList->next;
		while (p)
		{
			flight->List[i].WaitList->next = p->next;
			free(p);
			p = NULL;
		}
		free(flight->List[i].WaitList);
		flight->List[i].WaitList = NULL;
	}
	return 1;
}
bool DelFlightList(FlightList* flight)
{
	free(flight->List);
	flight->List = NULL;
	flight->capacity = 0;
	flight->sz = 0;
	return 1;
}
