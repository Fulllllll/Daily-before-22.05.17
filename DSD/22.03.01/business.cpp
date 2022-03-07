#include"business.h"

void query(FlightList* flight, char* t)
{
	char* q = t;
	plane* temp = NULL;
	int count = flight->sz;
	while (count != 0)
	{
		temp = &(flight->List[flight->sz - count--]);
		if (strcmp(q, temp->dest) == 0)
		{
			cout << "航班号：" << temp->flightnum << endl;
			cout << "飞行日期：" << temp->time << endl;
			cout << "飞机型号：" << temp->model << endl;
			cout << "A等座数量：" << temp->A << endl;
			cout << "B等座数量：" << temp->B << endl;
			cout << "C等座数量：" << temp->C << endl;
			cout << endl;

		}
	}
	cout << "终点站不存在" << endl;
}