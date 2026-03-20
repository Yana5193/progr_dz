#pragma once
#include <iostream>
using namespace std;
const int DEFAULT_CAPACITY = 10;
class ArrayException {};
class Array {
private:
	int* ptr;
	int size, capacity;
	void increaseCapacity(int newCapacity);
public:
    explicit Array(int startCapacity = DEFAULT_CAPACITY);
    Array(const Array& arr);
    ~Array();
    Array& operator =(const Array& arr);
    // Индексация 
    int& operator[](int index);

    // Вставка элемента 
    void insert(int elem, int index);
    void insert(int elem);  // вставка в конец

    // Удаление элемента 
    void remove(int index);

    int getSize() const;

    friend ostream& operator <<(ostream& out, const Array& arr);
};