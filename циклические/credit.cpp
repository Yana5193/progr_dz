#include <iostream>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	float credit;
	cout << "¬ведите размер кредита: ";
	cin >> credit;
	float procent;
	cout << "¬ведите размер процента: ";
	cin >> procent;
	float prib;
	cout << "¬ведите прибыль: ";
	cin >> prib;
	int y = 0;
	while (credit > 0) {
		credit = credit + credit * (procent / 100);
		credit = credit - prib;
		y = y + 1;
	}
	cout << " редит будет погашен за: " << y << "лет";
	return 0;
}
