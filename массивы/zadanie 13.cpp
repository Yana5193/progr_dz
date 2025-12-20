#include <iostream>
#include<windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 5;
    int n[size];
    int count[14] = { 0 };
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        cin >> n[i];
        count[n[i]]++;
    }
    bool Three = false;
    bool Four = false;
    int pairs = 0;

    for (int i = 1; i < 13; i++) {
        if (count[i] == 5) {
            cout << "1" << endl; 
            return 0;
        }
        else if (count[i] == 4) {
            Four = true;
        }
        else if (count[i] == 3) {
            Three = true; 
        }
        else if (count[i] == 2) {
            pairs++; 
        }
    }

    if (Four) {
        cout << "2" << endl; 
    }
    else if (Three and pairs==1) {
        cout << "3" << endl; 
    }
    else if (Three) {
       cout << "4" << endl; 
    }
    else if (pairs==2) {
        cout << "5" << endl; 
    }
    else if (pairs == 1) {
        cout << "6" << endl; 
    }
    else {
        cout << "7" << endl;
    }
    return 0;
}


