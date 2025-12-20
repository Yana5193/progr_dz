#include <iostream> 
#include<windows.h>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    int m;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;
    int matrix[30][30];
    cout << "Введите элементы матрицы(через пробел):";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];


        }
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j];
            }

        }
        else
            for (int j = n - 1; j >= 0; j--) {
                cout << matrix[i][j];
            }
        cout << endl;
    }
    system("pause");
    return 0;
}

