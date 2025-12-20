#include <iostream>
#include<windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int h, m, s;
    cout << "¬ведите часы, минуты и секунды: ";
    cin >> h >> m >> s;
//ѕереведем все врем€ в секунды
    double sec = h * 3600 + m * 60 + s;
    int min = round(sec / 60); //округление до минут
    int h_inmin = min / 60; // преобраз в часы 
    int m_inmin = min % 60;  // преобраз в мин
    int hours = round(sec / 3600.0); // округ до часов
    cout << "ќкругленное врем€ до минут: " << h_inmin << "ч " << m_inmin << "мин "<<endl;
    cout << "ќкругленное врем€ до часов: " << hours << "ч ";
    return 0;
}