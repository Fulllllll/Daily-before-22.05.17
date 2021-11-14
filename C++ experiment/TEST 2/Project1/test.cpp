#include<iostream>
using namespace std;
class cylinder {
private:
	double r, h, v;
public:
	cylinder(double r, double h);
	void vol();
};

cylinder::cylinder(double r, double h)
{
	this->r = r;
	this->h = h;
	this->v = 0.0;
}
void cylinder::vol()
{
	this->v = 3.14 * r * r * h;
	cout << "The volume of the cylinder is " << v<<endl;
}

int main()
{
	cylinder A(2, 2);
	A.vol();
	return 0;
}