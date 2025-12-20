#include <iostream>
#include<windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int l, m, sec;
    cout << "Введите градусы, минуты и секунды: ";
    cin >> l >> m >> sec;
    float p = 3.14;
    double grad,radian;
    grad = (l + ((m / 60.0) + (sec / 3600.0)));
    radian = (grad * p) / 180;
    cout << "Величина угла в радианах: " << radian;
    return 0;
}

