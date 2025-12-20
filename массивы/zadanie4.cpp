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
    int *mas=new int[n];
    cout << "Введите элементы массива: " ;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    int maxdlina = 0;
    int tekdlina = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] == 0) {
            tekdlina++;
        }
        else {
            if (tekdlina > maxdlina) {
                maxdlina = tekdlina;
            }
            tekdlina = 0;
        }

    }
    if (tekdlina > maxdlina) {
        maxdlina = tekdlina;
    }
    cout << "Длина самой длинной последовательности подряд идущих элементов массива, равных нулю: " << maxdlina << endl;
    delete [] mas;
    return  0;
}

