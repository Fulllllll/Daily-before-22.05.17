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
			printf("%6.0lf", p[i][j]);
		}
		cout << endl;
	}
}

Matrix Matrix::M_add(const Matrix& a)
{
	if (this->r != a.r && this->c != a.c)
	{
		cout << "����������������" << endl;
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
		cout << "����������������" << endl;
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
		cout << "����������������" << endl;
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
        cout << "����������������" << endl;
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
	if(r!=c||this->M_det()==0) 
	{
		cout << "����������������" << endl;
		exit(-1);
	}
	Matrix X(r, r, 2);
	if (r == 1)
	{
		X.p[r][r] = (double)1.0 / this->M_det();
	}
	int i, j, k, t;
	int N = r;
	Matrix temp(r-1, r-1, 2);
	int det = this->M_det();
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N - 1; k++)
			{
				for (t = 0; t < N - 1; t++)
				{
					temp.p[k][t] = temp.p[k >= i ? k + 1 : k][t >= j ? t + 1 : t];
				}
			}
			X.p[j][i] = pow(-1, i + j) * temp.M_det();
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			X.p[i][j] = temp.p[i][j] / det;
		}
	}

}
/*________________________________________________________________________________________________________
	---------------------------------------------------------------------------------------------------
	8*/
//int getA(int arcs[N][N], int n)//����һ��չ������|A|
//{
//	if (n == 1)
//	{
//		return arcs[0][0];
//	}
//	int ans = 0;
//	int temp[N][N];
//	int i, j, k;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n - 1; j++)
//		{
//			for (k = 0; k < n - 1; k++)
//			{
//				temp[j][k] = arcs[j + 1][(k >= i) ? k + 1 : k];
//
//			}
//		}
//		int t = getA(temp, n - 1);
//		if (i % 2 == 0)
//		{
//			ans += arcs[0][i] * t;
//		}
//		else
//		{
//			ans -= arcs[0][i] * t;
//		}
//	}
//	return ans;
//}
//void getAStart(int arcs[N][N], int n, int ans[N][N])//����ÿһ��ÿһ�е�ÿ��Ԫ������Ӧ������ʽ�����A*
//{
//	if (n == 1)
//	{
//		ans[0][0] = 1;
//		return;
//	}
//	int i, j, k, t;
//	int temp[N][N];
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			for (k = 0; k < n - 1; k++)
//			{
//				for (t = 0; t < n - 1; t++)
//				{
//					temp[k][t] = arcs[k >= i ? k + 1 : k][t >= j ? t + 1 : t];
//				}
//			}
//
//
//			ans[i][j] = getA(temp, n - 1);
//			if ((i + j) % 2 == 1)
//			{
//				ans[i][j] = -ans[i][j];
//			}
//		}
//	}
//}
//
//
//
//
//int main()
//{
//	int i, j;
//	int n;
//		int a = getA(arcs, n);
//		if (a == 0)
//		{
//			printf("can not transform!\n");
//		}
//		else
//		{
//			getAStart(arcs, n, astar);
//			for (i = 0; i < n; i++)
//			{
//				for (j = 0; j < n; j++)
//				{
//					printf("%.3lf ", (double)astar[i][j] / a);
//				}
//				printf("\n");
//			}
//		}
//	}
//}
//
//
//#include<stdio.h>
//#include<stdlib.h>    // �����ڴ�
//#include<math.h>  // pow()����,����-1��n�η������Բ������������͵��ʹ���ֳɵ�
//
///*________________________________________________________________________________________________________
//    ---------------------------------------------------------------------------------------------------
//	��������
//    һ��ʼ��ʹ�ó����б任���㣬�˺�������ɾ�����ò���
//    x1:������һ��
//    x2:�����ڶ���
//    order:�������
//    matrix:����
//    */
//void replaceRow(int x1, int x2, int order, float** matrix)
//{
//    float temp;
//    x1 -= 1;
//    x2 -= 1;
//    for (int i = 0; i < order; i++) {
//        temp = matrix[x1][i];
//        matrix[x1][i] = matrix[x2][i];
//        matrix[x2][i] = temp;
//    }
//}
//
///*
//    ת�þ���
//    matrix: ����
//    order: ����
//*/
//void transposeMatrix(float** matrix, int order)
//{
//    float temp;
//    for (int i = 0; i < order; i++) {
//        for (int j = 0; j < i; j++) {
//            temp = matrix[i][j];
//            matrix[i][j] = matrix[j][i];
//            matrix[j][i] = temp;
//        }
//    }
//}
//
///*
//    ��ȡ����ĳ��ĳ�еľ���
//    oldmatrix: ԭ������
//    newmatrix: �¾���
//    row: Ҫɾ����
//    col: Ҫɾ����
//    order: ����
//*/
//void get(float** oldmatrix, float** newmatrix, int row, int col, int order)
//{
//    // ɾ����һ��һ�У������¾������о���ԭ������1
//    int a = 0, b = 0;
//    int x, y, z = 0, w = 0;
//    // i,jѭ��ԭ����
//    for (int i = 0; i < order - 1; i++) {
//        for (int j = 0; j < order - 1; j++) {
//            // z,w�������е��Ƿ��һ״̬����ֹ��μ�һ��+1ֻ��Ҫ1��
//            if (i >= row && z == 0) { a += 1; z = 1; }
//            if (j >= col && w == 0) { b += 1; w = 1; }
//
//            newmatrix[i][j] = oldmatrix[i + a][j + b];
//        }
//        a = 0; b = 0;
//        z = 0; w = 0;
//    }
//}
//
///*
//    ��������ʽ
//    matrix: ����
//    order: ����
//*/
//
//
///*
//    ������
//*/
//int main()
//{
//    int order;    // �������
//    int i, j;
//    float det;
//
//    // ���㲢��ʾdet
//    det = calc(matrix, order);
//    printf("\ndetֵΪ��%f", det);
//    // 0����������
//
//    // ��ʾ�������
//    printf("\n����ľ����ǣ�\n\n");
//    showMatrix(matrix, order);
//
//    // �����ά����洢���
//    float** Rmatrix = (float**)malloc(sizeof(float*) * order);
//    for (i = 0; i < order; i++) {
//        Rmatrix[i] = (float*)malloc(sizeof(float) * order);
//    }
//
//
//    // ��ʼ����
//    if (order == 2) {
//        // ����Ϊ��ֱ�����й�ʽ
//        float n = 1 / (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
//        Rmatrix[0][0] = n * matrix[1][1];
//        Rmatrix[0][1] = -n * matrix[0][1];
//        Rmatrix[1][0] = -n * matrix[1][0];
//        Rmatrix[1][1] = n * matrix[0][0];
//    }
//    else {
//        // ת�þ�����ʾ
//        transposeMatrix(matrix, order);
//        printf("\n\nת�ú�Ϊ:\n\n");
//        showMatrix(matrix, order);
//
//        // ѭ����i��jλ�Ĵ�������ʽ
//        for (i = 0; i < order; i++) {
//            for (j = 0; j < order; j++) {
//                // �����ά����
//                order -= 1;
//                float** matrixlow = (float**)malloc(sizeof(float*) * order);
//                for (int t = 0; t < order; t++) {
//                    matrixlow[t] = (float*)malloc(sizeof(float) * order);
//                }
//                order += 1;
//
//                // ��ȡ����i��j�е�ֵ�������ʽ
//                get(matrix, matrixlow, i, j, order);
//                // ��������ʽֵ����det
//                Rmatrix[i][j] = pow(-1, i + j) * calc(matrixlow, order - 1) / det;
//
//                // �ͷ��ڴ�
//                for (int t = 0; t < order - 1; ++t)free(*(matrixlow + t));
//            }
//        }
//
//    }

//}