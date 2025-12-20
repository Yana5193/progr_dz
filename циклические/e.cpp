#include <iostream>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a, b;
	cout << "¬ведите координаты: ";
	cin >> a >> b;
	for (int x = -a; x <= a; ++x) {
		for (int y = -b; y <= b; ++y) {
			if (((x * x) / (a * a)) + ((y * y) / (b * b)) <= 1) {
				cout << x << " " << y << endl; 
			}
		}
	}

return 0;
}