#include<iostream>
#include<string>
using namespace std;

class book {
public:
	book(int a);
	void display();
private:
	int qu;
	int price;
};
book::book(int a)
{
	qu = a;
	price = a * 10;
}
void book::display()
{
	cout << qu * price << endl;
}

int main()
{
	book A[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		A[i].display();
	}
	cout << endl;
	book* p = A;
	for (int i = 0; i < 5; i++)
	{
		(p + 4 - i)->display();
	}
	return 0;
}