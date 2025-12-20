#include<iostream> 
#include<windows.h> 
using namespace std;
int NOD(int a, int b) {
	if (b == 0) {
		return a;
	}
	return NOD(b, a % b);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, b;
	cout << "Введите первое число:";
	cin >> a;
	cout << "Введите второе число:";
	cin >> b;
	cout << "Наибольший общий делитель: " << NOD(a, b);
	system("pause");
	return 0;
}
