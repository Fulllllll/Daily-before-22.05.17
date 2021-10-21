#include<iostream>
#include"function.h"
int main()
{

	//Matrix A(2, 3);
	//Matrix B(2, 3);
	//Matrix X = A.M_add(B);
	//X.M_show();

	//≤‚ ‘æÿ’Û≥À
	//Matrix C(3, 1);
	//Matrix X = A.M_mul(C);
	//X.M_show();

	//≤‚∑Ω’Û ‘––¡– Ω
	//Matrix A(3, 3);
	//cout << A.M_det() << endl;

	//≤‚ ‘ƒÊæÿ’Û
	Matrix A(3, 3);
	Matrix X = A.M_inverse();
	X.M_show();
	return 0;
}