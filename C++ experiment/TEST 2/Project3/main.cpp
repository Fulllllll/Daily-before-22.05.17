#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#define MAX 15
using namespace std;
class Stock {
private:
	char stocknode[MAX];
	int quan;
	double price;
public:
	Stock(const char na[] , int q, double p);
	void print();
};

Stock::Stock(const char na[], int q=1000, double p=8.98)
{
	strcpy(stocknode, na);
	quan = q;
	price = p;
}

void Stock::print()
{
	cout << "stockcode: " << stocknode << endl;
	cout << "quantity: " << quan << endl;;
	cout << "price: " << price << endl;
}
int main()
{
	Stock A("600001", 3000, 6.57);
	Stock B("600001");
	A.print();
	cout << endl;
	B.print();
	return 0;
}
