#pragma once
#include<iostream>
using namespace std;
template<class T> class LineListElem {
	T data;
	LineListElem* next;

public:
	LineListElem(const T& aData, LineListElem* aNext);
	const T& getData() const;
	LineListElem* getNext();

	template <class T> friend class LineList;
};
template<class T> class LineList {
	LineListElem<T>* start;

	LineList(const LineList& list); //запрет копирования
	LineList& operator =(const LineList& list)=delete;
public:
	LineList();
	~LineList();
	LineListElem<T>* getStart();
	void deleteFirst();
	void deleteAfter(LineListElem<T>* ptr);
	void insertFirst(const T& data);
	void insertAfter(LineListElem<T>* ptr, const T& data);
	template <class T>
	friend std::ostream& operator<<(std::ostream& out, LineList<T>& list);

};
