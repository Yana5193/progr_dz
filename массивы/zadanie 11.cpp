#include <iostream>
#include<windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int pice_para = 105;
    int price_sv = 1025;
    int price_box = 11400;
    int n;
    cout << "Введите количество пар: ";
    cin >> n;
    int n3 = n / (12 * 12);
    n = n- n3 * (12 * 12);
    int n2 = n / 12;
    n = n - n2 * 12;
    int n1 = n/2;
    cout << "Необходимо купить:" << endl;
    cout << "Коробок: " << n3 <<endl;
    cout << "Связок: " << n2 <<endl;
    cout << "Пар носков: " << n1 <<endl;


}


