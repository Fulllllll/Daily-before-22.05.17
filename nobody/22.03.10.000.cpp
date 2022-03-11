#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;
//#include<iostream>
//using namespace std;
//
//int func(int a, int b) {
//
//	if (a < 1 || b < 1)
//		return 0;
//	else if (a == 1 || b == 1)
//		return 1;
//	else if (a < b) 
//		return func(a, a);
//	else if (a == b) 
//		return 1 + func(a, b - 1);
//	else 
//		return func(a, b - 1) + func(a - b, b);
//}
//
//int main() {
//
//	//int n = 0;
//	//cin >> n;
//	//cout << func(n, n) << endl;
//	for (int i = 1; i <= 10; i++)
//	{
//		cout << i << "的划分数为" << func(i, i) <<endl;
//	}
//}




//int b[100] = { 0 };
//
//void Merge(int c[], int d[], int l, int m, int r);
//void MergePass(int x[], int y[], int s, int n);
//void MergeSort1(int a[], int l, int r);
//void MergeSort2(int a[], int n);
//void copy(int a[], int b[], int l, int r);
//
//
//
//int main()
//{
//	int a[100] = { 6,5,4,3,2,1,7,8,9,12,11,10 }; //12个元素
//	MergeSort1(a, 0, 11);
//	//MergeSort2(a, 12);
//	for (int i = 0; i < 12; i++)
//	{
//		printf("%d  ", a[i]);
//	}
//	return 0;
//}
//
//void Merge(int c[], int d[], int l, int m, int r)
//{
//	int i = l, j = m + 1, k = l;
//	while ((i <= m) && (j <= r))
//	{
//		if (c[i] <= c[j])
//			d[k++] = c[i++];
//		else
//			d[k++] = c[j++];
//		if (i > m)
//		{
//			for (int q = j; q <= r; q++)
//				d[k++] = c[q];
//		}
//		else
//		{
//			for (int q = i; q <= m; q++)
//				d[k++] = c[q];
//		}
//	}
//}
//
//void MergePass(int x[], int y[], int s, int n)
//{
//	int i = 0;
//	while (i <= n - 2 * s)
//	{
//		Merge(x, y, i, i + s - 1, i + 2 * s - 1);
//		i = i + 2 * s;
//	}
//	if (i + s < n)
//	{
//		Merge(x, y, i, i + s - 1, n - 1);
//	}
//	else
//		for (int j = i; j <= n - 1; j++)
//		{
//			y[j] = x[j];
//		}
//}
//
//void MergeSort1(int a[], int l, int r)
//{
//	if (l < r)
//	{
//		int i = (l + r) / 2;
//		MergeSort1(a, l, i);
//		MergeSort1(a, i + 1, r);
//		Merge(a, b, l, i, r);
//		copy(a, b, l, r);
//	}
//}
//void MergeSort2(int a[], int n)
//{
//	int* b = NULL;
//	int s = 1;
//	while (s < n)
//	{
//		MergePass(a, b, s, n);
//		s += s;
//		MergePass(b, a, s, n);
//		s += s;
//	}
//}
//
//void copy(int a[], int b[], int l, int r)
//{
//	for (int i = l; i <= r; i++)
//	{
//		a[i] = b[i];
//	}
//}


//void QuickSort(int left, int right, int a[])
//{
//	if (left >= right)
//		return;
//	int i, j, base, temp;
//	i = left, j = right;
//	base = a[left];  
//	while (i < j)
//	{
//		while (a[j] >= base && i < j)
//			j--;
//		while (a[i] <= base && i < j)
//			i++;
//		if (i < j)
//		{
//			temp = a[i];
//			a[i] = a[j];
//			a[j] = temp;
//		}
//	}
//	a[left] = a[i];
//	a[i] = base;
//	QuickSort(left, i - 1, a);
//	QuickSort(i + 1, right, a);
//}
//
//int main()
//{
//	int a[12] = { 6, 5, 4, 3, 2, 1, 7, 8, 9, 12, 11, 10 };
//	QuickSort(0, 11, a);
//	for (int i = 0; i < 12; i++)
//	{
//		printf("%d  ", a[i]);
//	}
//	return 0;
//}



int b[100] = { 0 };

void Merge(int c[], int d[], int l, int m, int r);
void mergepass(int x[], int y[], int s, int n);
void MergeSort1(int a[], int l, int r);
void MergeSort2(int a[], int n);
void copy(int a[], int b[], int l, int r);

int main()
{
	int a[100] = { 6,5,4,3,2,1,7,8,9,0,11,10 }; //12个元素
	//MergeSort1(a, 0, 11);
	MergeSort2(a, 12);
	for (int i = 0; i < 12; i++)
	{
		printf("%d  ", a[i]);
	}
	return 0;
}

void Merge(int c[], int d[], int l, int m, int r)
{
	int i = l, j = m + 1, k = l;
	while ((i <= m) && (j <= r))
	{
		if (c[i] <= c[j])
			d[k++] = c[i++];
		else
			d[k++] = c[j++];
	}
	if (i > m)
	{
		for (int q = j; q <= r; q++)
			d[k++] = c[q];
	}
	else
	{
		for (int q = i; q <= m; q++)
			d[k++] = c[q];
	}
}

void mergepass(int x[], int y[], int s, int n)
{
	int i = 0;
	while (i <= n - 2 * s)
	{
		Merge(x, y, i, i + s - 1, i + 2 * s - 1);
		i += 2 * s;
	}
	if (i + s < n)
	{
		Merge(x, y, i, i + s - 1, n - 1);
	}
	else
	{
		for (int j = i; j <= n - 1; j++)
		{
			y[j] = x[j];
		}
	}
}

void MergeSort1(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		MergeSort1(a, l, m);
		MergeSort1(a, m + 1, r);
		Merge(a, b, l, m, r);  
		copy(a, b, l, r);
	}
}
void MergeSort2(int a[], int n)
{
	int s = 1;
	while (s < n)
	{
		mergepass(a, b, s, n);
		s += s;
		mergepass(b, a, s, n);
		s += s;
	}
}

void copy(int a[], int b[], int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		a[i] = b[i];
	}
}


//#include <iostream>
//#include <vector>
//#include <string>
//#include <utility>
//using namespace std;
//
//int word_analysis(vector<pair<string, int>>& word, const string expr)
//{
//	for (int i = 0; i < expr.length(); ++i)
//	{
//		// 如果是 + - * / ( )
//		if (expr[i] == '(' || expr[i] == ')' || expr[i] == '+'
//			|| expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
//		{
//			string tmp;
//			tmp.push_back(expr[i]);
//			switch (expr[i])
//			{
//			case '+':
//				word.push_back(make_pair(tmp, 1));
//				break;
//			case '-':
//				word.push_back(make_pair(tmp, 2));
//				break;
//			case '*':
//				word.push_back(make_pair(tmp, 3));
//				break;
//			case '/':
//				word.push_back(make_pair(tmp, 4));
//				break;
//			case '(':
//				word.push_back(make_pair(tmp, 6));
//				break;
//			case ')':
//				word.push_back(make_pair(tmp, 7));
//				break;
//			}
//		}
//		// 如果是数字开头
//		else if (expr[i] >= '0' && expr[i] <= '9')
//		{
//			string tmp;
//			while (expr[i] >= '0' && expr[i] <= '9')
//			{
//				tmp.push_back(expr[i]);
//				++i;
//			}
//			if (expr[i] == '.')
//			{
//				++i;
//				if (expr[i] >= '0' && expr[i] <= '9')
//				{
//					tmp.push_back('.');
//					while (expr[i] >= '0' && expr[i] <= '9')
//					{
//						tmp.push_back(expr[i]);
//						++i;
//					}
//				}
//				else
//				{
//					return -1;  // .后面不是数字，词法错误
//				}
//			}
//			word.push_back(make_pair(tmp, 5));
//			--i;
//		}
//		// 如果以.开头
//		else
//		{
//			return -1;  // 以.开头，词法错误
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	vector<pair<string, int>> word;
//	string expr = "6+2*(2+13";
//
//	int err_num = word_analysis(word, expr);
//	if (-1 == err_num)
//		cout << "Word Error!" << endl;
//	else
//		cout << "No Word Error!" << endl;
//	return 0;
//}
