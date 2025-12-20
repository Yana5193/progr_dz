#include <iostream>
#include<windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX_SIZE = 100; 
    int size;
    int X[MAX_SIZE]; 
    cout << "Введите размер массива (максимум " << MAX_SIZE << "): ";
    cin >> size;
    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> X[i];
    }
    int dlinposled = 1;
    int tekposled = 1;
    for (int i = 1; i < size; ++i) {
        if ((X[i] > X[i - 1] && (i == 1 || X[i - 1] <= X[i - 2])) ||
            (X[i] < X[i - 1] && (i == 1 || X[i - 1] >= X[i - 2]))) {
                tekposled++; 
       }
        else if (X[i] != X[i - 1]) {
            tekposled = 2; 
        }

        dlinposled = max(dlinposled, tekposled); 
    }
    cout << "Длина самой длинной последовательности: " << dlinposled;
    return 0;


}

