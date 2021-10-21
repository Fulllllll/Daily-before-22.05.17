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
Matrix::~Matrix()
{
	for (int i = 0; i < r; i++)
	{
		delete[]p[i];
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
			printf("%.3lf   ", p[i][j]);
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

double Matrix::M_F(const Matrix& a)
{
	double x = 0.0;
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++)
		{
			x += pow(p[i][j], 2);
		}
	return sqrt(x);
}

double Matrix::M_det()
{
    if (r != c)
    {
        cout << "矩阵不满足运算条件" << endl;
        exit(-1);
    }
	double det = 0.0;
    int N = c;
    if (N == 1)
        return p[0][0];
    if (N == 2)
        return p[0][0] * p[1][1] - p[1][0] * p[0][1];
    for (int i = 0; i < N; i++)
    {
        Matrix X(N - 1, N - 1, 2);
        for (int j =0; j < N-1; j++)
            for (int k = 0; k < N-1; k++)
            {
                X.p[j][k] = p[j + 1][k < i ? k : k + 1];
            }
        if (p[0][i])
            det += p[0][i] * X.M_det() * (((2 + i) % 2) ? -1 : 1);
    }
    return det;
}


Matrix Matrix::M_inverse()
{
	double det = this->M_det();
	
	if(r!=c||det==0) 
	{
		cout << "矩阵不满足运算条件" << endl;
		exit(-1);
	}
	Matrix X(r, r, 2);
	if (r == 1)
	{
		X.p[r][r] = (double)1.0 / det;
		return X;
	}
	int i, j, k, t;
	int N = r;
	Matrix temp(r-1, r-1, 2);
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N - 1; k++)
			{
				for (t = 0; t < N - 1; t++)
				{
					temp.p[k][t] = p[i > k ? k : k + 1][j > t ? t : t + 1];
				}
			}
			X.p[j][i] = pow(-1, i + j) * temp.M_det()/det;
		}
	}
	return X;
}