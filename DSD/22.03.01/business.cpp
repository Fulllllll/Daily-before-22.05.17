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
			cout << "����ţ�" << temp->flightnum << endl;
			cout << "�������ڣ�" << temp->time << endl;
			cout << "�ɻ��ͺţ�" << temp->model << endl;
			cout << "A����������" << temp->A << endl;
			cout << "B����������" << temp->B << endl;
			cout << "C����������" << temp->C << endl;
			cout << endl;

		}
	}
	cout << "�յ�վ������" << endl;
}