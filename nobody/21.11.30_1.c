#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 0; a < 5; a++)
	{
		for (b = 0; b < 5; b++)
		{
			for (c = 0; c < 5; c++)
			{
				for (d = 0; d < 5; d++)
				{
					for (e = 0; e < 5; e++)
					{
						int A[2] = { b == 2, a == 3 };
						int B[2] = { b == 2, e == 4 };
						int C[2] = { c == 1, d == 2 };
						int D[2] = { c == 5, d == 3 };
						int E[2] = { e == 4, a == 1 };
						if (A[0] + A[1] == 1 && B[0] + B[1] == 1 && C[0] + C[1] == 1 && D[0] + D[1] == 1 && E[0] + E[1] == 1)
							if(a+b+c+e+d==15)
							printf("A %d\tB %d\tC %d\tD %d\tE %d",a,b,c,d,e);
					}
				}
			}
		}
	}

	return 0;
}



//int main() {
//	int arr[4] = { 0 };
//	int i = 0;
//	for (i = 0; i < 4; i++) {
//		arr[i] = 1;
//		int ARR[4] = { arr[0] == 0,arr[2] == 1,arr[3] == 1,arr[3] == 0 };
//		int True = 0;
//		for (int i = 0; i < 4; i++)
//		{
//			True += ARR[i];
//		}
//		if (True == 3)
//		{
//			printf("%c", i + 'A');
//		}
//		arr[i] = 0;
//	}
//	return 0;
//}


//#define N 8
//
//int main()
//{
//	int i = 0, j = 0;
//	int a[N][N];
//	for (i = 0; i < N; i++)
//	{
//		a[i][0] = 1;
//		a[i][i] = 1;
//	}
//	for (i = 2; i < N; i++)
//	{
//		for (j = 1; j < i; j++)
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//		}
//	}
//	for (i = 0; i < N; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ",a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
