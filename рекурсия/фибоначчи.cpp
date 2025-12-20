#include <iostream>
using namespace std;
int fib(int n) {
    if (n == 1) return 0; 
    if (n == 2) return 1; 
    int a = 0; 
    int b = 1; 
    int c;
    for (int i = 3; i <= n; ++i) {
        c = a + b; 
        a = b;     
        b = c;    
    }
    return c; 
}
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите n: ";
    cin >> n;

    cout << n << "-е число Фибоначчи: " << fib(n) << endl;

    return 0;
}

