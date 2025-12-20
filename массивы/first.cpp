#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 3;
    int b[size] = { 1, 0, 1 }; // это число 5 
    cout << "Исходное число :";
    for (int i = 0; i < size; i++) {
        cout << b[i];
    }
    bool perepolnenie = true;
    for (int i = size - 1; i >= 0; i--) {
        if (b[i] == 0) {
            b[i] = 1;
            perepolnenie = false;
            break;
        }
        else {
            b[i] = 0; 
        }
    }
    cout << "Массив для M+1: ";
    if (perepolnenie) {
        for (int i = 0; i < size; i++) {
            cout << "1" << b[i];
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << b[i];
        }
    }
   
    return 0;
}



