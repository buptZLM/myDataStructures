#pragma once
#include<sstream>
#include"linearList.h"
#include"myExceptions.h"
#include"changeLength1D.h"
template<typename T>
class arrayList :public linearList<T>
{
private:
	int listSize;
	int capacity;
	T* element;
	void checkIndex(int index)const;
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList & x);
	~arrayList();

	bool empty()const { return listSize == 0; }
	int getSize()const { return listSize; }
	int getCapacity()const { return capacity; }
	T& get(int index)const;
	T& getFirst()const;
	T& getLast()const;
	int find(const T& theElement)const;
	//int* findAll(const T& theElement)const;
	void insert(int index, const T& theElement);
	void addFirst(const T& theElement);
	void addLast(const T& theElement);
	void erase(int index);
	void removeFirst();
	void removeLast();
	void removeAll(const T& theElement);
	void output(ostream& out)const;
};
template<typename T>
void arrayList<T>::checkIndex(int index)const {
	if (index < 0 || index >= listSize) {
		ostringstream s;
		s << "index = " << index << " must be >0 or <listSize";
		throw illegalIndexValue(s.str());
	}
}
template<typename T>
arrayList<T>::arrayList(int initialCapacity) {
	capacity = initialCapacity;
	listSize = 0;
	element = new T[capacity];
}
template<typename T>
arrayList<T>::arrayList(const arrayList& x) {
	capacity = x.capacity;
	listSize = x.listSize;
	element = new T[capacity];
	for (int i = 0; i < listSize; i++) {
		element[i] = x.element[i];
	}
}
template<typename T>
arrayList<T>::~arrayList() {
	delete[]element;
}
template<typename T>
T& arrayList<T>::get(int index)const {
	checkIndex(index);
	return element[index];
}
template<typename T>
int arrayList<T>::find(const T& theElement)const {
	for (int i = 0; i < listSize; i++) {
		if (element[i] == theElement)
			return i;
	}
	return -1;
}
template<typename T>
void arrayList<T>::insert(int index, const T& theElement) {
	if (index<0 || index>listSize) {
		throw illegalIndexValue("illegal index value");
	}
	if (listSize == capacity) {
		changeLength1D(element, capacity, 2 * capacity);
		capacity *= 2;
	}
		for (int i = listSize; i > index; i--) {
				element[i] = element[i-1];
			}
		element[index] = theElement;
	listSize++;
}
template<typename T>
void arrayList<T>::addFirst(const T& theElement) {
	insert(0, theElement);
}
template<typename T>
void arrayList<T>::addLast(const T& theElement) {
	insert(listSize, theElement);
}
template<typename T>
void arrayList<T>::erase(int index) {
	checkIndex(index);
	for (int i = index+1; i<listSize; i++) {
		element[i - 1] = element[i];
	}
	element[--listSize].~T();
}
template<typename T>
void arrayList<T>::removeAll(const T& theElement) {
	for (;find(theElement) >= 0;) {
		erase(find(theElement));
	}
}
template<typename T>
void arrayList<T>::output(ostream& out)const {
	out << "listSize = " << listSize << ", capacity = " << capacity << endl;
	for (int i = 0; i<listSize; i++) {
		out << element[i];
	}
}
template<typename T>
ostream& operator<<(ostream& out, const arrayList<T>& x) {
	x.output(out); return out;
}
template<typename T>
T& arrayList<T>::getFirst()const {
	return get(0);
}
template<typename T>
T& arrayList<T>::getLast()const {
	return get(listSize - 1);
}
template<typename T>
void arrayList<T>::removeFirst(){
	 erase(0);
}
template<typename T>
void arrayList<T>::removeLast() {
	 erase(listSize-1);
}