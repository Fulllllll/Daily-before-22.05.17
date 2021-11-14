#include<iostream>
#include<string>
using namespace std;

class Stock{
private:
	string stocknode;
	int quantity;
	double price;
public:
	Stock();
	Stock(string s, int a, double b);
	void print();
};

Stock::Stock()
{
	stocknode = "   ";
}
//Stock::Stock(string s, int a, double b)
//{
//	stockcode = s;
//	quantity = a;
//	price = b;
//}
//Stock::Stock(string s)
//{
//	stockcode = s;
//	quantity = 1000;
//	price = 8.98;
//}
//合二为一：
Stock::Stock(string s, int a = 1000, double b = 8.98)
{
	stocknode = s;
	quantity = a;
	price = b;
}


void Stock::print() 
{
	cout << "stockcode: " << stocknode << endl;
	cout << "quantity: " << quantity << endl;;
	cout << "price: " << price << endl;
}

int main()
{
	Stock A("600001", 3000, 6.57);
	Stock B("600001");
	A.print();
	cout << endl;
	B.print();
	//cout << endl << endl;
	//Stock C;
	//C.print();
	return 0;
}
