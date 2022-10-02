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
#include "matrix.h"
using namespace std;

Matrix::Matrix() {
    rows = 0;
    columns = 0;
    matrix = NULL;
}
Matrix::Matrix(int rows, int columns) {
    if (rows > 0)
        this->rows = rows;
    else throw "Недопустимое значение!";
    if (columns > 0)
        this->columns = columns;
    else throw "Недопустимое значение!";

    matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new double[columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = i+j;
}