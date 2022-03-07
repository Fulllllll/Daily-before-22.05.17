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
	while (strcmp(buf, "飞机") == 0 && (!feof(fp)))
	{
		//	
		// 动态增加容量
		//
		temp = &(flight->List[flight->sz++]);
		fscanf(fp, "航班号:%s ", temp->flightnum);
		fscanf(fp, "到达站:%s ", temp->dest);
		fscanf(fp, "起飞时间:%s ", temp->time);
		fscanf(fp, "机型:%s\n", temp->model);
		fscanf(fp, "票务信息\n A:%d B:%d C:%d\n", &(temp->A), &(temp->B), &(temp->C));
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
			fscanf(fp, "航班号:%s ", ODList->List[ODList->sz].flightnum);
			fscanf(fp, "姓名:%s ", ODList->List[ODList->sz].name);
			fscanf(fp, "A:%d ", &(ODList->List[ODList->sz].A));
			fscanf(fp, "B:%d ", &(ODList->List[ODList->sz].B));
			fscanf(fp, "C:%d\n", &(ODList->List[ODList->sz++].C));
		}
		else if (flag == 1)
		{
			//AddWaitList;
			char planename[10] = { 0 };
			fscanf(fp, "航班号:%s ", planename);
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
			fscanf(fp, "姓名:%s ", p->order.name);
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
		fprintf(fp, "飞机\n");
		fprintf(fp, "航班号:%s ", temp->flightnum);
		fprintf(fp, "到达站:%s ", temp->dest);
		fprintf(fp, "起飞时间:%s ", temp->time);
		fprintf(fp, "机型:%s\n", temp->model);
		fprintf(fp, "票务信息\n A:%d B:%d C:%d\n", temp->A, temp->B, temp->C);
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
	for (int i = 0; i < ODList->sz; i++)   //保存正常订单
	{	
		fprintf(fp, "0 ");
		fprintf(fp, "航班号:%s ", ODList->List[i].flightnum);
		fprintf(fp, "姓名:%s ", ODList->List[i].name);
		fprintf(fp, "A:%d ", ODList->List[i].A);
		fprintf(fp, "B:%d ", ODList->List[i].B);
		fprintf(fp, "C:%d\n", ODList->List[i].C);
	}
	for (int i = 0; i < flight->sz; i++)	//保存后补订单
	{
		Waitlist p = flight->List[i].WaitList->next;
		while (p)
		{
			fprintf(fp, "1 ");
			fprintf(fp, "航班号:%s ", p->order.flightnum);
			fprintf(fp, "姓名:%s ", p->order.name);
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
	//释放正常订单空间
	free(ODList->List);
	ODList->List = NULL;
	ODList->capacity = 0;
	ODList->sz = 0;
	//释放候补订单空间
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
