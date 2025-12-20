#include <iostream>
#include <windows.h>
#include <cmath> 
#define M_PI 3.14159265358979323846
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Функция y = x^4" << endl;
    double eps = 1e-6;
    bool fun = true; 
    bool sad = true;
    for (double x = -5; x <= 5; x += 0.5) {
        double f_x = x * x * x * x;
        double f_p_x = (-x) * (-x) * (-x) * (-x);
        if (fabs(f_x - f_p_x)<eps) {
            fun = false; 
            break;
        }
        if (fabs(f_x + f_p_x) < eps) {
            sad = false;
            break;
        }
    }
    if (fun) {
        cout << "Функция четная" << endl;
    }
    else {
        cout << "Функция нечетная" << endl;
    }

    cout << "Функция y = tg(x)" << endl;
    bool fun = true; 
    bool sad = true;
    for (double x = -M_PI; x <= M_PI; x += 0.5) {
        double y_x = tan(x);
        double y_p_x = tan(-x);
        if (fabs(y_x - y_p_x) < eps) {
            fun = false;
            break;
        }
        if (fabs(y_x + y_p_x) < eps) {
            sad = false;
            break;
        }
        if (y_p_x != -y_x) {
            fun = false; 
            break;
        }
    }
    if (fun) {
        cout << "Функция y = tan(x) является нечетной" << endl;
    }
    else {
        cout << "Функция y = tan(x) не является нечетной" << endl;
    }

    cout << "Функция y = e^x" << endl;
    bool fun = true; 
    for (double x = -5; x <= 5; x += 0.1) {
        double f_x = exp(x);
        double f_p_x = exp(-x);
        if (f_p_x != f_x) {
            fun = false; 
            break;
        }
        if (fabs(f_x - f_p_x) < eps) {
            fun = false;
            break;
        }
        if (fabs(f_x + f_p_x) < eps) {
            sad = false;
            break;
        }

    }
    if (fun) {
        cout << "Функция y = e^x является четной" << endl;
    }
    else {
        cout << "Функция y = e^x не является четной" << endl;
    }

    return 0;
}
