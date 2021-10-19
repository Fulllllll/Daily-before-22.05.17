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
	if(r!=c||this->M_det()==0) 
	{
		cout << "矩阵不满足运算条件" << endl;
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
//int getA(int arcs[N][N], int n)//按第一行展开计算|A|
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
//void getAStart(int arcs[N][N], int n, int ans[N][N])//计算每一行每一列的每个元素所对应的余子式，组成A*
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
//#include<stdlib.h>    // 操作内存
//#include<math.h>  // pow()函数,计算-1的n次方，可以不用这个函数，偷懒使用现成的
//
///*________________________________________________________________________________________________________
//    ---------------------------------------------------------------------------------------------------
//	交换两行
//    一开始想使用初等行变换计算，此函数可以删除，用不到
//    x1:调换第一行
//    x2:调换第二行
//    order:矩阵阶数
//    matrix:矩阵
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
//    转置矩阵
//    matrix: 矩阵
//    order: 阶数
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
//    获取除了某行某列的矩阵
//    oldmatrix: 原本矩阵
//    newmatrix: 新矩阵
//    row: 要删除行
//    col: 要删除列
//    order: 阶数
//*/
//void get(float** oldmatrix, float** newmatrix, int row, int col, int order)
//{
//    // 删除了一行一列，所以新矩阵行列均比原矩阵少1
//    int a = 0, b = 0;
//    int x, y, z = 0, w = 0;
//    // i,j循环原矩阵
//    for (int i = 0; i < order - 1; i++) {
//        for (int j = 0; j < order - 1; j++) {
//            // z,w代表行列的是否加一状态，防止多次加一，+1只需要1次
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
//    计算行列式
//    matrix: 矩阵
//    order: 阶数
//*/
//
//
///*
//    主函数
//*/
//int main()
//{
//    int order;    // 矩阵阶数
//    int i, j;
//    float det;
//
//    // 计算并显示det
//    det = calc(matrix, order);
//    printf("\ndet值为：%f", det);
//    // 0不能做除数
//
//    // 显示输入矩阵
//    printf("\n输入的矩阵是：\n\n");
//    showMatrix(matrix, order);
//
//    // 申请二维数组存储结果
//    float** Rmatrix = (float**)malloc(sizeof(float*) * order);
//    for (i = 0; i < order; i++) {
//        Rmatrix[i] = (float*)malloc(sizeof(float) * order);
//    }
//
//
//    // 开始计算
//    if (order == 2) {
//        // 阶数为二直接运行公式
//        float n = 1 / (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
//        Rmatrix[0][0] = n * matrix[1][1];
//        Rmatrix[0][1] = -n * matrix[0][1];
//        Rmatrix[1][0] = -n * matrix[1][0];
//        Rmatrix[1][1] = n * matrix[0][0];
//    }
//    else {
//        // 转置矩阵并显示
//        transposeMatrix(matrix, order);
//        printf("\n\n转置后为:\n\n");
//        showMatrix(matrix, order);
//
//        // 循环求i，j位的代数余子式
//        for (i = 0; i < order; i++) {
//            for (j = 0; j < order; j++) {
//                // 申请二维数组
//                order -= 1;
//                float** matrixlow = (float**)malloc(sizeof(float*) * order);
//                for (int t = 0; t < order; t++) {
//                    matrixlow[t] = (float*)malloc(sizeof(float) * order);
//                }
//                order += 1;
//
//                // 获取除了i，j行的值组成行列式
//                get(matrix, matrixlow, i, j, order);
//                // 计算行列式值除以det
//                Rmatrix[i][j] = pow(-1, i + j) * calc(matrixlow, order - 1) / det;
//
//                // 释放内存
//                for (int t = 0; t < order - 1; ++t)free(*(matrixlow + t));
//            }
//        }
//
//    }

//}