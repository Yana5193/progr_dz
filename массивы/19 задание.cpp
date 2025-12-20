#include<locale.h>
#include <iostream>
#include <unordered_set>
using namespace std;
bool lsq(int** p, int n) {
    for (int i = 0; i < n; i++) {
        unordered_set<int> rowSet;
        for (int j = 0; j < n; j++) {
            if (p[i][j] < 1 || p[i][j] > n || rowSet.count(p[i][j])) {
                return false; 
            }
            rowSet.insert(p[i][j]);
        }
    }
    for (int j = 0; j < n; ++j) {
        std::unordered_set<int> colSet;
        for (int i = 0; i < n; ++i) {
            if (p[i][j] < 1 || p[i][j] > n || colSet.count(p[i][j])) {
                return false; 
            }
            colSet.insert(p[i][j]);
        }
    }
    return true;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер массива:";
    cin >> n;
    int** p = new int*[n];
    for (int i = 0; i < n; i++) {
        p[i] = new int[n];
    }
    cout << "Введите элементы массива:";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    if (lsq(p, n)) {
        cout << "Является латинским квадратом";
    }
    else {
        cout << "Не является латинскими квадратом";
    }
    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete[] p[i];
    }
    delete[] p;

    return 0;
}


