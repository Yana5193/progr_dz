#include<windows.h>
#include<algorithm>
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
    sort(mas, mas + n);
    for (int i = 0; i < n - 1; i++) {
        if (mas[i] == mas[i + 1]) {
            cout << "Повторяющееся число: " << mas[i] << endl;
            delete[] mas;
            return 0;

        }
    }

    cout << "Повторяющихся чисел нет" << endl;
    delete[] mas;
    return 0;
}
