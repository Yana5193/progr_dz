#include <iostream>
#include <vector>
#include <locale.h>
#include "human.h"
#include "student.h"
using namespace std;
int main(int argc, char* argv[]) {
	vector<int> scores;
	setlocale(LC_ALL, "rus");

	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(2);
	scores.push_back(2);
	scores.push_back(5);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);
	scores.push_back(3);

	// Создание объекта класса student
	student* stud = new student("Петров", "Иван", "Алексеевич", scores);

	// Вывод полного имени студента
	cout << stud->get_full_name() << endl;
	// Вывод среднего балла студента
	cout << "Средний балл: " << stud->get_average_score() << endl;

	system("pause");
	return 0;
}