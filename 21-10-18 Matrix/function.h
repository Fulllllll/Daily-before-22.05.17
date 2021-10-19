#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

class Matrix
{
	int r, c;
public:
	double** p;
	Matrix(int a, int b);
	Matrix(int a, int b,int );
	Matrix(const Matrix& a);
	void M_show();
	Matrix M_add(const Matrix& a);
	Matrix M_sub(const Matrix& a);
	Matrix M_mul(const Matrix& a);
	Matrix M_inverse(const Matrix& a);
	double M_F(const Matrix& a);

};