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

int get_key()
{
    int key = _getch();
    if ((key == 0) || (key == 224))
        key = _getch();
    return key;
}

int menu1()
{
    cout << "\nMatrix Class.\n\n"
        "1 - View/edit the studied matrices.\n"
        "2 - Matrix Addition(+)\n"
        "3 - Matrix difference(-)\n"
        "4 - multiplication matrix(*)\n"
        "5 - Multiplying a matrix by a scalar\n"
        "6 - Dividing a matrix by a scalar\n"
        "7 - Calculating the trace of the matrix\n"
        "8 - Checking vectors for coplanarity\n\n"
        "Exit: Esc";


    while (true)
    {
        int key = get_key();
        if ((key == 27) || (key > '0' && key <= '8'))
            return key;
    }
}

int menu2()
{
    cout << "\n\n";
    cout << "Resume: Enter";
    while (true)
    {
        int key = get_key();
        if (key == 13) return key;
    }
}

int menu3()
{
    cout << "1 - Yes\n2 - No";
    while (true)
    {
        int key = get_key();
        if (key == '1' || key == '2') return key;
    }
}

bool double_control(char* xn)
{
    char* tmp = xn;
    int zap_p = 0;
    const char mask[] = ".-1234567890";
    int checker = 0;
    while (*tmp)
    {
        if (strchr(mask, *tmp)) checker++;
        tmp++;
    }
    if (checker != strlen(xn))
        return false;
    if (checker == 0)
        return false;

    if (*xn == '-' && *(xn + 1) == '\0')
    {
        return false;
    }
    if ((*xn == ','))
        return false;

    tmp = xn;
    while (*tmp)
    {
        if ((*tmp == ','))
        {
            zap_p++;
        }
        if ((*(tmp + 1) == '-') || (*tmp == '\0'))
        {
            return false;
        }
        tmp++;
    }
    if (zap_p > 1) return false;
    return true;
}

double double_checker()
{
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = double_control(n_data);
        if (check == true) break;
        else
        {
            cout << "  Invalid sitax! Try again: ";
        }
    }
    double data = (double)atof(n_data);
    return data;
}

//int
bool int_control(char* xn)
{
    char* tmp = xn;
    int zap_p = 0;
    const char mask[] = "-1234567890";
    int checker = 0;
    while (*tmp)
    {
        if (strchr(mask, *tmp)) checker++;
        tmp++;
    }
    if (checker != strlen(xn))
        return false;
    if (checker == 0)
        return false;

    if (*xn == '-' && *(xn + 1) == '\0')
    {
        return false;
    }
    if ((*xn == ','))
        return false;

    tmp = xn;
    while (*tmp)
    {
        if ((*tmp == ','))
        {
            zap_p++;
        }
        if ((*(tmp + 1) == '-') || (*tmp == '\0'))
        {
            return false;
        }
        tmp++;
    }
    if (zap_p > 1) return false;
    return true;
}

int int_checker()
{
    char n_data[64];
    while (true) {
        gets_s(n_data);
        bool check = int_control(n_data);
        if (check == true) break;
        else
        {
            printf("  Invalid sitax! Try again: ");
        }
    }
    int data = (int)atoi(n_data);
    return data;
}

Matrix operator * (double h, Matrix matrix);
Matrix operator / (double h, Matrix matrix);
std::ostream& operator << (std::ostream& s, const Matrix& matrix);


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "");

    Matrix A(2, 2), B(2, 2), C(2, 2);
    A(0, 0) = 1;
    A(0, 1) = 2;
    A(1, 0) = 3;
    A(1, 1) = 4;

    B(0, 0) = 1;
    B(0, 1) = 2;
    B(1, 0) = 3;
    B(1, 1) = 4;

    Matrix jajaja(A);
    cout << jajaja;
    while (true) {
        system("cls");
        int m1 = menu1();
        switch (m1) {
        case 27: return 0;
        case 49: {
            system("cls");
            cout << "\tInvestigated matrices:\n\n";
            cout << "A:\n" << A << endl;
            cout << "B:\n" << B;

            cout << "\n\nDo you want to change the matrices?" << endl;
            int m3 = menu3();
            switch (m3) {
            case 49: {
                system("cls");
                cout << "\n--------Setting the matrix A--------" << endl;
                A.EnterMatrix();

                cout << "\n--------Setting the matrix B--------" << endl;
                B.EnterMatrix();

                break;
            }
            case 50: {
                break;
            }
            }

            break;
        }
        case 50: {
            system("cls");
            cout << "\tMatrix Addition.\n\n";
            bool check = 0;
            try {
                C = A + B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                cout << "A + B:\n\n" << endl;
                cout << A << "\n +\n\n" << B << "\n = \n\n";
                cout << A + B;
            }

            break;
        }
        case 51: {
            system("cls");
            cout << "\tMatrix difference.\n\n";
            bool check = 0;
            try {
                C = A - B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                C = A - B;
                cout << "A - B:\n\n" << endl;
                cout << A << "\n -\n\n" << B << "\n = \n\n";
                cout << C;
            }

            break;
        }
        case 52: {
            system("cls");
            cout << "\tmultiplication matrix.\n\n";
            bool check = 0;
            try {
                C = A * B;
                check = 1;
            }
            catch (const char* message) {
                cout << message;
            }

            if (check) {
                C = A * B;
                cout << "A * B:\n\n" << endl;
                cout << A << "\n *\n\n" << B << "\n = \n\n";
                cout << C;
            }

            break;
        }
        case 53: {
            system("cls");
            cout << "\tMultiplying a matrix by a scalar.\n\n";
            double a;
            cout << "Enter a value (scalar): ";
            a = double_checker();
            cout << "A * a:\n\n" << endl;
            cout << A << "\n *\n\n " << a << "\n\n = \n\n";
            C = A * a;
            cout << C;

            break;
        }
        case 54: {
            system("cls");
            cout << "\tDividing a matrix by a scalar.\n\n";
            double a;
            cout << "Enter a value (scalar): ";
            a = double_checker();
            //  cin.get();
            cout << "A \ a:\n\n" << endl;
            cout << A << "\n /\n\n " << a << "\n\n = \n\n";
            C = A / a;
            cout << C;

            break;
        }
        case 55: {
              system("cls");
              cout << "\tCalculating the trace of the matrix.\n\n";
              cout << "Tr(A) = " << A.tr();
              break;
          }
        case 56: {
            system("cls");
            cout << "Checking vectors for coplanarity." << endl;
            Matrix test;
            test.CreateMatrixForCheck();
            test.CheckTheDeterminant();
            break;
          }
        }
        while (true)
        {
            int m2 = menu2();
            if (m2 == 13) break;
        }
    }
    return 0;
}
