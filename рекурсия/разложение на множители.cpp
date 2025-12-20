#include<locale.h>
#include <iostream>
using namespace std;
void f(int n) {
    if (n == 1) return;

    for (int d = 2; d <= n; d++) {
        if (n % d == 0) {
            cout << d << " ";
            f(n / d);
            return;
        }
    }
}
int main() {
    int n;
    cin >> n;
    f(n);
    return 0;
}


