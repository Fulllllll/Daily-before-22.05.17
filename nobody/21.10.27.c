#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<easyx.h>
int main()
{

	return 0;
}
//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10};
//	int l = 0, r = sizeof(a)/ sizeof(a[0])-1;
//	int mid = 0;
//	while (l <= r)  //查找 7
//	{
//		mid = (l + r) / 2;
//		if (7 < a[mid])
//			r = mid;
//		else if (7 > a[mid])
//			l = mid + 1;
//		else
//			break;
//	}
//	printf("%d", mid);//查找输出元素的下标
//	return 0;
//}
//
//int main()
//{
//	int i = 1, j = 1;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2.d\t", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int a[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	int max = a[0];
//	for (i = 1; i < 10; i++)
//	{
//		if (a[i] > max) max = a[i];
//	}
//	printf("%d\n", max);
//}

//int main()
//{
//	double sum = 0.0;
//	int flag = 1;
//	for (int i = 1; i <= 100; i++)
//	{
//		sum += (1.0 / i) * flag;
//		flag = -flag;
//	}
//	printf("%lf", sum);
//	return 0;
//}

//int main()
//{
//	int n;
////注意这里定义的是分子的1,必须是float型
//	int j = 1;
//	float sum = 0;
//	for (n = 1; n <= 100; n++)//循环100个数出来
//	{
//		sum = sum + (1.0 / n) * j;//数学表达式
//		j = -j;//用于正负号转换
//
//	}
//	printf("%f\n", sum);
//	return 0;
//}
//int main()
//{
//	int n=0;
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i / 9 == 0 || i % 9 == 0)
//			n++;
//	}
//	printf("%d", n);
//}




//int main()
//{
//	int i = 0;
//	for (i = 101; i < 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j < i / 2; j++)
//		{
//			if (i % j==0) break;
//		}
//		if (j >= i / 2) printf("%d ", i);
//	}
//	return 0;
//}



//int main()
//{
//	int i;
//	for (i = 1000; i < 2000; i+=4)
//	{
//		if ((i % 4 == 0 && i % 100) || i % 400 == 0)
//		{
//			printf("%d\t", i);
//		}
//	}
//	return 0;
//}



//int main()
//{
//	int m,n,r;
//	scanf("%d %d",&m,&n);
//	while(r=m%n)
//	{
//		m=n;
//		n=r;
//	}
//	printf("%d",n);
//	return 0;
//}