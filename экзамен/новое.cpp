#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;                      // сколько точек
double ras[10][10];         // расстояния
int best[10];               // лучшее паросочетание
double min_sum = 1e9;       // минимальная сумма

// перебирает все варианты
void perebor(int p[], int k, bool used[]) {
    if (k == n) { // если все красные разобрали
        double s = 0;
        for (int i = 0; i < n; i++) {
            s += ras[i][p[i]]; // сумма расстояний
        }
        if (s < min_sum) { // если нашли лучше
            min_sum = s;
            for (int i = 0; i < n; i++) {
                best[i] = p[i]; // запомнили лучшее
            }
        }
        return;
    }

    // пробуем все синие для текущей красной
    for (int i = 0; i < n; i++) {
        if (!used[i]) { // если синяя свободна
            used[i] = true; // заняли
            p[k] = i;       // соединили
            perebor(p, k + 1, used); // дальше рекурсия
            used[i] = false; // освободили (назад)
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    cout << "Введите количество точек: ";
    cin >> n;
    double kx[10], ky[10]; // красные x,y
    double sx[10], sy[10]; // синие x,y
    // генерим точки
    cout << "\nКрасные:\n";
    for (int i = 0; i < n; i++) {
        kx[i] = rand() % 60;
        ky[i] = rand() % 60;
        cout << i + 1 << ": " << kx[i] << " " << ky[i] << endl;
    }

    cout << "\nСиние:\n";
    for (int i = 0; i < n; i++) {
        sx[i] = rand() % 60;
        sy[i] = rand() % 60;
        cout << i + 1 << ": " << sx[i] << " " << sy[i] << endl;
    }

    // считаем расстояния
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double dx = kx[i] - sx[j];
            double dy = ky[i] - sy[j];
            ras[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

    // перебор
    int p[10];
    bool used[10] = { false };
    perebor(p, 0, used);

    // результат
    cout << "\nЛучший вариант:\n";
    for (int i = 0; i < n; i++) {
        cout << "К" << i + 1 << " -> С" << best[i] + 1
            << " = " << ras[i][best[i]] << endl;
    }
    cout << "Сумма: " << min_sum << endl;

    return 0;
}