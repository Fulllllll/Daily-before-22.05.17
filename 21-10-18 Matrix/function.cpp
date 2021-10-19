#include"function.h"

Matrix::Matrix(int a, int b)
{
	r = a;
	c = b;
	p= new double*[r];
	for (int i = 0; i < r; i++)
	{
		p[i] = new double[c];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> p[i][j];
		}
	}
}
Matrix::Matrix(int a, int b,int )
{
	r = a;
	c = b;
	p = new double* [r];
	for (int i = 0; i < r; i++)
	{
		p[i] = new double[c];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			p[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& a)
{
	r = a.r;
	c = a.c;
	p = new double* [r];
	for (int i = 0; i < r; i++)
	{
		p[i] = new double[c];
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			p[i][j] = a.p[i][j];
		}
	}
}


void Matrix::M_show()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%6.0lf", p[i][j]);
		}
		cout << endl;
	}
}

Matrix Matrix::M_add(const Matrix& a)
{
	if (this->r != a.r && this->c != a.c)
	{
		cout << "矩阵不满足运算条件" << endl;
		exit(-1);
	}
	Matrix temp(r, c,2);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			temp.p[i][j] = p[i][j] + a.p[i][j];
		}
	}
	return temp;
}

Matrix Matrix::M_sub(const Matrix& a)
{
	if (this->r != a.r && this->c != a.c)
	{
		cout << "矩阵不满足运算条件" << endl;
		exit(-1);
	}
	Matrix temp(r, c, 2);
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			temp.p[i][j] = p[i][j] - a.p[i][j];
		}
	}
	return temp;
}
Matrix Matrix::M_mul(const Matrix& a)
{
	if (c!=a.r)
	{
		cout << "矩阵不满足运算条件" << endl;
		exit(-1);
	}
	Matrix temp(r, a.c, 2);
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < a.c; j++)
			for (int k = 0; k < c; k++)
			{
				temp.p[i][j] += (this->p[i][k] * a.p[k][j]);
			}
		
	return temp;
}

//Matrix Matrix::M_inverse(const Matrix& a)
//{
//
//}
//
//double Matrix::M_F(const Matrix& a)
//{
//	
//}