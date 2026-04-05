#include "datatime.h"
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Полная демонстрация"<<endl;

    cout << "1. Проверка разных форматов ввода:"<<endl;

    DateTime d1;
    d1.parse("2025-04-05");                 
    cout << "Только дата:           "; d1.print(); cout << endl;

    DateTime d2;
    d2.parse("2021-12-21T07:54:34");           
    cout << "Дата + время:";
    d2.print(); 
    cout << endl;

    DateTime d3;
    d3.parse("2025-04-05T15:30:00");           
    cout << "Дата + время (другое): "; 
    d3.print(); 
    cout << endl;

    DateTime d4;
    d4.parse("14:30:45");                     
    cout << "Только время:";
    d4.print();
    cout << endl;

    cout << "2. Проверка корректности:"<<endl;
    DateTime bad;
    bad.parse("2025-02-30");                  
    cout << "Некорректная дата (30 февраля): "; bad.print();
    cout << "  ? Корректна? " << (bad.isValid() ? "Да" : "Нет") << endl;

 
    cout << "3. Основные операции:"<<endl;
    cout << "Разница d3 - d2 = " << (d3 - d2) << " дней\n";

    DateTime d5 = d3 + 10;
    cout << "d3 + 10 дней = "; d5.print(); cout << endl;

    cout << "4. Сравнения:"<<endl;
    cout << "d3 > d2  ? " << (d3 > d2 ? "Да" : "Нет") << endl;
    cout << "d3 == d3 ? " << (d3 == d3 ? "Да" : "Нет") << endl;
    cout << "d2 <= d3 ? " << (d2 <= d3 ? "Да" : "Нет") << endl;

    
    cout << "5. День недели:"<<endl;
    cout << "Для даты "; d3.print2();
    cout << " — "; d3.printWeekday(); cout << endl;
}

