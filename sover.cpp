#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Поиск совершенных чисел. Введите максимум: ";
	cin >> n;
	if (n < 6)
	{
		cout << "Совершенных чисел не найдено" << endl;
		return 0;
	}
	for (int i = 6; i <= n; i++) // Числа
	{
		int sum = 1; // Сумма делителей
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				sum += j;
				// Чтобы не тратить зря время
				if (sum > i)
					break;
			}
		}
		if (sum != i)
			continue;
		cout << i << "=1+"; sum = 1;
		for (int j = 2; j <= i / 2; j++)
			if (i % j == 0)
			{
				cout << j;
				sum += j;
				if (sum == i) // Если последний делитель найден
				{
					cout << endl;
					break;
				}
				else cout << "+"; // Делитель не последний
			}
	}
	return 0;
}

