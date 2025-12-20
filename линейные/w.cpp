#include <iostream>
#include<windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double radian;
	cout << "Введите радиану: ";
	cin >> radian;
	double grad;
	grad = (radian * 180) / M_PI;
	double min;
	min = radian * (60 * 180) / M_PI;
	double sec;
	sec = radian * (3600 * 180) / M_PI;
	cout << "Величина угла в градусах : " << grad << endl;
	cout << "Величина угла в минутах : " << min << endl;
	cout << "Величина угла в секундах : " << sec << endl;
	return 0;
}