#include <iostream>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, b, c;
	cout << "Введите координаты a,b,c: ";
	cin >> a >> b >> c;
	int x, y;
	x = (b * (-1)) / 2 * a;
	y = ((4 * a * c) - (b * b)) / 4 * a;
	cout << "Абсцисса: " << x << endl;
	cout << "Ордината: " << y << endl;
	return 0;


}