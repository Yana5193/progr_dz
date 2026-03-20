#include "array.h"
#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Russian");
    int n, k;
    cout << "Введите размер массива: ";
    cin >> n;
    cout << "Введите количество шагов: ";
    cin >> k;
    clock_t start = clock();
    Array arr(n);  
    for (int i = 1; i <= n; i++) {  
        arr.insert(i);
    }

    int in = 0;
    while (arr.getSize() > 1) {
        in = (in + k - 1) % arr.getSize();
        arr.remove(in);  
    }

    int result = arr[0];  
    clock_t end = clock();
    double time = double(end - start) / CLOCKS_PER_SEC;

    cout << "Время расчета: " << time << " секунд" << endl;

    ofstream csvFile("test.csv", ios::app);
    ifstream checkFile("test.csv");
    bool fileExists = checkFile.good();
    checkFile.close();

    if (!fileExists) {
        ofstream newFile("test.csv");
        newFile << "N;Ответ;Время расчета (сек)" << endl;  
        newFile.close();
        csvFile.open("test.csv", ios::app);
    }
    csvFile << n << ";" << result << ";" << time << endl;  
    csvFile.close();

    return 0;
}