#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
void InsertionSort(int* arr, int size) {
    auto start = high_resolution_clock::now();
    for (int i = 1; i < size; i++) {
        int buf = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > buf) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = buf;
    }
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "Затрачено: " << diff.count() << " секунд\n";
}
void HeapSort(int* arr, int size) {
    auto start = high_resolution_clock::now();

    for (int i = size / 2 - 1; i >= 0; i--) {
        int root = i;
        while (2 * root + 1 < size) {
            int child = 2 * root + 1;
            if (child + 1 < size && arr[child] < arr[child + 1])
                child++;
            if (arr[root] < arr[child]) {
                int tmp = arr[root];
                arr[root] = arr[child];
                arr[child] = tmp;
                root = child;
            }
            else break;
        }
    }
    for (int i = size - 1; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        int root = 0;
        while (2 * root + 1 < i) {
            int child = 2 * root + 1;
            if (child + 1 < i && arr[child] < arr[child + 1])
                child++;
            if (arr[root] < arr[child]) {
                int t = arr[root];
                arr[root] = arr[child];
                arr[child] = t;
                root = child;
            }
            else break;
        }
    }
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "Затрачено: " << diff.count() << " секунд\n";
}
void QuickSortRec(int* arr, int first, int last) {
    int i = first, j = last;
    int pivot = arr[(first + last) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int buf = arr[i];
            arr[i] = arr[j];
            arr[j] = buf;
            i++;
            j--;
        }
    }

    if (first < j) QuickSortRec(arr, first, j);
    if (i < last) QuickSortRec(arr, i, last);
}

void QuickSort(int* arr, int size) {
    auto start = high_resolution_clock::now();
    QuickSortRec(arr, 0, size - 1);
    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "Затрачено: " << diff.count() << " секунд\n";
}
void BucketSort(int* arr, int n) {
    auto start = high_resolution_clock::now();

    int** b = new int* [n];
    int* k = new int[n];

    for (int i = 0; i < n; i++) {
        b[i] = new int[n];
        k[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int x = arr[i] / 10;
        b[x][k[x]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        InsertionSort(b[i], k[i]);
        for (int j = 0; j < k[i]; j++)
            arr[index++] = b[i][j];
    }

    for (int i = 0; i < n; i++)
        delete[] b[i];
    delete[] b;
    delete[] k;

    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "Затрачено: " << diff.count() << " секунд\n";
}
void MergeSort(int arr[], int size) {
    auto start = high_resolution_clock::now();

    for (int block = 1; block < size; block *= 2) {
        for (int j = 0; j < size - block; j += 2 * block) {
            int lb = j;
            int mb = j + block;
            int rb = (j + 2 * block < size) ? j + 2 * block : size;

            int i = lb, k = mb, pos = 0;
            int* temp = new int[rb - lb];

            while (i < mb && k < rb)
                temp[pos++] = (arr[i] < arr[k]) ? arr[i++] : arr[k++];
            while (i < mb) temp[pos++] = arr[i++];
            while (k < rb) temp[pos++] = arr[k++];

            for (int t = 0; t < pos; t++)
                arr[lb + t] = temp[t];

            delete[] temp;
        }
    }

    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    cout << "Затрачено: " << diff.count() << " секунд\n";
}
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Исходный массив:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    cout << "1 - Вставками\n"
        << "2 - Пирамидальная\n"
        << "3 - Быстрая\n"
        << "4 - Блочная\n"
        << "5 - Слиянием\n"
        << "Выбор: ";

    int c;
    cin >> c;
    cout << "\n";

    switch (c) {
    case 1: InsertionSort(arr, n); break;
    case 2: HeapSort(arr, n); break;
    case 3: QuickSort(arr, n); break;
    case 4: BucketSort(arr, n); break;
    case 5: MergeSort(arr, n); break;
    default: cout << "Ошибка\n";
    }

    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr;
    return 0;
}
