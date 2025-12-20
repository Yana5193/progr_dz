#include <iostream>
#include<windows.h>
#include <iomanip>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const double MILE_TO_KM = 1.609344;
    int k;
    cout << "Введите максимальное расстояние км: ";
    cin >> k;
    cout << fixed << setprecision(4);
    cout << "мили\t\tкм" << endl;
    for (int km = 1; km < k; km++) {
        double mili = km / MILE_TO_KM;
        cout << mili << "\t\t" << km << ".0000" << endl;
    }
    cout << "Значения для целых миль:" << endl;
    for (int mili = 1; mili <= k; mili++) {
        double km = mili * MILE_TO_KM;
        cout << mili << ".0000\t\t" << km << endl;
    }
    return 0;
}

