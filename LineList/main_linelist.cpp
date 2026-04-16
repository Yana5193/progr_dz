#include "linelist.h"
#include <iostream>  
#include <fstream>   
#include <ctime>    
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int N, k;
    cout << "Введите количество людей (N): ";
    cin >> N;
    cout << "Введите шаг считалки (k): ";
    cin >> k;
    clock_t t1 = clock();
    LineList<int> circle;
    for (int i = N; i >= 1; i--) {
        circle.insertFirst(i);
    }
    int currentSize = N;
    LineListElem<int>* curr = circle.getStart();
    while (currentSize > 1) {
        for (int i = 1; i < k - 1; i++) {
            curr = curr->getNext();
            if (curr->getNext() == nullptr) {
                curr = circle.getStart();
            }
        }
        if (k == 1) {
            circle.deleteFirst();
            curr = circle.getStart();
        }
        else {
            if (curr->getNext() == nullptr) {
                circle.deleteFirst();
                curr = circle.getStart();
            }
            else {
                circle.deleteAfter(curr);
                if (curr->getNext() == nullptr) {
                    curr = circle.getStart();
                }
                else {
                    curr = curr->getNext();
                }
            }
        }
        currentSize--;
    }
    int winner = circle.getStart()->getData();
    clock_t t2 = clock();
    double duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
    cout << "Ответ: " << winner << endl;
    cout << "Время расчета: " << duration << " сек." << endl;
    ofstream csv("result.csv", ios::app);
    ifstream check("result.csv");
    check.seekg(0, ios::end);
    bool isEmpty = (check.tellg() <= 0);
    check.close();

    if (isEmpty) {
        csv << "N;Ответ;Время (сек)" << endl;
    }
    csv << N << ";" << winner << ";" << duration << endl;
    csv.close();
    return 0;
}