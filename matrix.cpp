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
double& Matrix::operator () (int i, int j) {
    if ((i >= 0) && (i < rows) && (j >= 0) && (j < columns))
        return matrix[i][j];
    else throw "Некорректные значения индексов!";
}
Matrix Matrix::operator + (const Matrix& rhs) {
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
        return result;
    }
    throw "Размерности матриц не совпадают! Сложение матриц с разными размерностями недопустимо!";
}
Matrix Matrix::operator - (const Matrix& rhs) {
    if ((rows == rhs.rows) && (columns == rhs.columns)) {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                result.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
        return result;
    }
    throw "Размерности матриц не совпадают! Вычитание матриц с разными размерностями недопустимо!";
}
Matrix Matrix::operator * (const Matrix& rhs) {
    if (columns == rhs.rows) {
        Matrix result(rows, rhs.columns);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.columns; j++)
                result.matrix[i][j] = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < rhs.columns; j++)
                for (int k = 0; k < columns; k++)
                    result.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
        return result;
    }
    throw "Матрицы не могут быть перемножены! Недопустимая размерность!";
}
Matrix Matrix::operator * (const double h) {
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result.matrix[i][j] = matrix[i][j] * h;
    return result;
}
Matrix Matrix::operator / (const double h) {
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result.matrix[i][j] = matrix[i][j] / h;
    return result;
}
void Matrix::EnterMatrix() {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    cout << "Введите размерность матрицы:" << endl;
    cout << "Количество строк: ";
    int newRows = int_checker();
    cout << "Количество столбцов: ";
    int newColumns = int_checker();

    Matrix newMatrix(newRows, newColumns);
    for (int i = 0; i < newRows; i++)
        for (int j = 0; j < newColumns; j++) {
            cout << "Ячейка (" << i << ", " << j << ") = ";
            newMatrix.matrix[i][j] = double_checker();
        }

    rows = newRows;
    columns = newColumns;
    matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new double[columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = newMatrix.matrix[i][j];
}
Matrix operator * (double h, Matrix matrix) {
    Matrix result(matrix.GetRows(), matrix.GetCols());
    result = matrix * h;
    return result;
}
Matrix operator / (double h, Matrix matrix) {
    Matrix result(matrix.GetRows(), matrix.GetCols());
    result = matrix / h;
    return result;
}
ostream& operator<< (ostream& s, const Matrix& matrix) {

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++)
            s << matrix.matrix[i][j] << " ";
        s << "\n";
    }
    return s;
}