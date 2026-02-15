#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int N = 200;
double dist[N][N], u[N], v[N], minv[N];
int p[N], way[N];
bool used[N];
int n;

bool dfs(int i) {
    p[0] = i;
    int j0 = 0;

    for (int j = 0; j <= n; j++) {
        minv[j] = 1e18;
        used[j] = false;
    }

    do {
        used[j0] = true;
        int i0 = p[j0];
        double delta = 1e18;
        int j1 = 0;

        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                double cur = dist[i0][j] - u[i0] - v[j];
                if (cur < minv[j]) {
                    minv[j] = cur;
                    way[j] = j0;
                }
                if (minv[j] < delta) {
                    delta = minv[j];
                    j1 = j;
                }
            }
        }

        for (int j = 0; j <= n; j++) {
            if (used[j]) {
                u[p[j]] += delta;
                v[j] -= delta;
            }
            else {
                minv[j] -= delta;
            }
        }

        j0 = j1;
    } while (p[j0] != 0);

    do {
        int j1 = way[j0];
        p[j0] = p[j1];
        j0 = j1;
    } while (j0 != 0);

    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Введите n: ";
    cin >> n;

    if (n <= 0 || n >= N) {
        cout << "Ошибка: n должно быть от 1 до " << N - 1 << endl;
        return 1;
    }

    srand(time(0));

    double red_x[N], red_y[N], blue_x[N], blue_y[N];

    // Генерация точек
    cout << "\nКрасные точки:\n";
    for (int i = 1; i <= n; i++) {
        red_x[i] = rand() % 100;
        red_y[i] = rand() % 100;
        cout << i << ": " << red_x[i] << " " << red_y[i] << endl;
    }

    cout << "\nСиние точки:\n";
    for (int i = 1; i <= n; i++) {
        blue_x[i] = rand() % 100;
        blue_y[i] = rand() % 100;
        cout << i << ": " << blue_x[i] << " " << blue_y[i] << endl;
    }

    // Матрица расстояний
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            double dx = red_x[i] - blue_x[j];
            double dy = red_y[i] - blue_y[j];
            dist[i][j] = sqrt(dx * dx + dy * dy);
        }
    }

    // Инициализация
    for (int i = 0; i <= n; i++) {
        u[i] = v[i] = 0;
        p[i] = 0;
    }

    // Алгоритм
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }

    // Результат
    double sum = 0;
    cout << "\nПаросочетание:\n";
    for (int j = 1; j <= n; j++) {
        sum += dist[p[j]][j];
        cout << "R" << p[j] << " → B" << j << ": "
            << fixed << setprecision(3) << dist[p[j]][j] << endl;
    }

    cout << fixed << setprecision(3);
    cout << "\nСумма: " << sum << endl;

    return 0;
}