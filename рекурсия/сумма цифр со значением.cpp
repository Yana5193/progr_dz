#include <iostream>
#include<locale.h>
using namespace std;
bool proverka(int n, int s) {
    if (n == 0)
        return s == 0;
    return proverka(n / 10, s - n % 10);

}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    int s;
    cin >> n >> s;
    cout << (proverka(n, s) ? "сумма совпадает" : "сумма не совпадает");
    return 0;
}

