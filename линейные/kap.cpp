#include <iostream>
#include<windows.h>
#include<cmath>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double k;
    cout << "Введите стартовый капитал: ";
    cin >> k;
    double p;
    cout << "Введите процент: ";
    cin >> p;
    double s;
    cout << "Введите сумму: ";
    cin >> s;
    int n;
    n = log (s) / log(k * (1 + p));
    cout << "Количество лет: " << n;
    return 0;
} 
