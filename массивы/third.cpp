#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int m[8000];
    int count = 0;
    for (int i = 1000; i < 10000; i++) {
        int a = i / 1000;
        int b = i / 100 % 10;
        int c = i / 10 % 10;
        int d = i % 10;
        if (a != b and a != c and a != d and b != c and b != d and c != d) {
            m[count++] = i;
        }
    }
    cout << "Все четырехзначные натуральные числа, в десятичной записи которых нет двух одинаковых цифр: ";
    for (int i = 0; i < count; i++) {
        cout << m[i]<<" ";
    }
    return 0;
}
