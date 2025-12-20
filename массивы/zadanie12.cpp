#include<locale.h>
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 100;
    int size;
    int X[MAX_SIZE];
    cout << "Введите размер массива (максимум " << MAX_SIZE << "): ";
    cin >> size;
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        cin >> X[i];
    }
    int maximlen = 0;
    for (int start = 0; start < size; start++) {
        for (int end = start; end < size; end++) {
            bool simetriya = true;
            int dlina = end - start + 1;
            for (int i = 0; i < dlina / 2; i++) {
                if (X[start + i] != X[end - i]) {
                    simetriya = false;
                    break;
                }
            }
            if (simetriya and dlina > maximlen) {
                maximlen = dlina;
            }
        }
    }
    cout << "Длина отрезка= " << maximlen << endl;
    return 0;
    
}

