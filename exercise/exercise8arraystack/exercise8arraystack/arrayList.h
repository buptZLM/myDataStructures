#pragma once
#include"linearList.h"
#include<sstream>
#include"changeLength1D.h"
#include"myExceptions.h"
template<typename T>
class arrayList :public linearList<T>
{
private:
	int size;
	int capacity;
	T* element;
	void checkIndex(int index)const;
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>& x);
	~arrayList();

	bool empty()const { return size == 0; }
	int getSize()const { return size;}
	int getCapacity()const { return capacity; }
	T& get(int index)const;
	T& getFirst()const;
	T& getLast()const;
	int find(const T& theElement)const;
	void insert(int index,const T& theElement);
	void addFirst(const T& theElement);
	void addLast(const T& theElement);
	void erase(int index);
	void removeFirst();
	void removeLast();
	void output(ostream& out)const;
};
template<typename T>
arrayList<T>::arrayList(int initialCapacity) {
	if (initialCapacity < 0)
		throw illeaglParameterValue();
	size = 0;
	capacity = initialCapacity;
	element = new T[capacity];
}
template<typename T>
arrayList<T>::arrayList(const arrayList<T>& x) {
	size = x.size;
	capacity = x.capacity;
	element = new T[capacity];
	for (int i = 0; i < size; i++) {
		element[i] = x.element[i];
	}
}
template<typename T>
arrayList<T>::~arrayList() {
	delete[] element;
}
template<typename T>
void arrayList<T>::checkIndex(int index)const {
	if (index < 0 || index >= size) {
		ostringstream s;
		s << "index = " << index << " must be >=0 or <size";
		throw illeaglIndexValue(s.str());
	}
}

template<typename T>
T& arrayList<T>::get(int index)const {
	checkIndex(index);
	return element[index];
}

template<typename T>
T& arrayList<T>::getFirst()const {
	return get(0);
}
template<typename T>
T& arrayList<T>::getLast()const {
	return get(size - 1);
}
template<typename T>
int arrayList<T>::find(const T& theElement)const {
	for (int i = 0; i < size; i++) {
		if (element[i] == theElement)
			return i;
	}
	return -1;
}
template<typename T>
void arrayList<T>::insert(int index, const T& theElement) {
	if (index<0 || index>size)
		throw illeaglParameterValue("index must be >=0 or <= size");
	if (size == capacity) {
		changeLength1D(element, capacity, 2 * capacity);
		capacity *= 2;
	}
		
	for (int i = size; i > index; i--)
		element[i] = element[i - 1];
	element[index] = theElement;
	size++;
}
template<typename T>
void arrayList<T>::addFirst(const T& theElement) {
	insert(0, theElement);
}
template<typename T>
void arrayList<T>::addLast(const T& theElement) {
	insert(size, theElement);
}
template<typename T>
void arrayList<T>::erase(int index) {
	checkIndex(index);
	if (size <= (capacity / 4)){
		changeLength1D(element, capacity, capacity / 2);
		capacity =(capacity / 2);
	}
	for (int i = index + 1; i < size; i++) {
		element[i - 1] = element[1];
	}
	size--;
}
template<typename T>
void arrayList<T>::removeFirst() {
	erase(0);
}
template<typename T>
void arrayList<T>::removeLast() {
	erase(size-1);
}
template<typename T>
void arrayList<T>::output(ostream& out)const {
	out << "size = " << size << "  capacity = " << capacity<<" [";
	for (int i = 0; i < size; i++) {
		out << element[i];
		if (i != size - 1)
			out << ", ";
	}
	out << " ] ";
}
template<typename T>
ostream& operator<<(ostream& out, const arrayList<T>& x) {
	x.output(out);
	return out;
}