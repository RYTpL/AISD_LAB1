#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
using namespace std;

class Matrix
{
private:
	int rows, columns;
	double** matrix;

public:
	Matrix();
	Matrix(int rows, int columns);
	void EnterMatrix();
	double& operator () (int i, int j);
	Matrix operator + (const Matrix& rhs);
	Matrix operator - (const Matrix& rhs);
	Matrix operator * (const Matrix& rhs);
	Matrix operator * (const double h);
	Matrix operator / (const double h);
	friend Matrix operator * (double h, Matrix matrix);
	friend Matrix operator / (double h, Matrix matrix);
	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);

};