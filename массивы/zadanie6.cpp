#include<windows.h>
#include <iostream>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    int* mas = new int[n];
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    int neravnul = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] != 0) {
            mas[neravnul] = mas[i];
            neravnul++;
        }
    }
    for (int i = neravnul; i < n; i++) {
        mas[i] = 0;
    }
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << mas[i];
    }
    return 0;
}
