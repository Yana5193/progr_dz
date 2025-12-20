#include <iostream>
#include<windows.h>
#include <cmath> 
#define M_PI 3.14159265358979323846
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double eps = 1e-6;
    cout << " Функция y = sin^2x " << endl;
    bool fun = true;
    for (double x = 0; x <= 5 * M_PI; x += 0.1) {
        double f_x = pow(sin(x), 2);
        double f_p_x = pow(sin(x+M_PI), 2);
        if (f_x- f_p_x>eps) {
            fun = false;
            break;
        }
        if (fun) {
            cout << "Функция периодическая" << endl;
        }
        else {
            cout << "Функция не периодическая" << endl;
        }
    }
    cout << "Функция y = tg(x)" << endl;
    for (double x = 0; x <= 5 * M_PI; x += 0.1) {
        double f_x = tan(x);
        double f_p_x = tan(x) + M_PI;
        if (cos(x) == 0) {
            cout << "Тангенс не определен в точках, где cos(x) = 0 (разрыв)" << endl;
        }
        else {
            cout << "tan(" << x << ") = " << tan(x) << endl;
        }
        if (f_x - f_p_x > eps) {
            cout << "Функция не периодическая" << endl;
        }
        else{
            cout << "Функция периодическая" << endl;
        }

    }
    cout << "Функция 1/x*sin x" << endl;
    for (double x = 0; x <= 5 * (2 * M_PI); x += 0.1) {
        double f_x = (1 / x) * sin(x);
        double f_p_x = (1 / x) * sin(x) + M_PI;
        if (x == 0) {
            cout << "Функция не определена в точке 0 (разрыв)" << endl;

        }
        else {
            cout << " 1/x*sin x(" << x << ") = " << (1 / x) * sin(x) << endl;

        }
        if (f_x - f_p_x > eps) {
            cout << "Функция не периодическая" << endl;
        }
        else {
            cout << "Функция периодическая" << endl;
        }
    }
    return 0;
}