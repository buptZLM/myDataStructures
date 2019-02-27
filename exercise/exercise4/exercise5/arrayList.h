#pragma once
#include<sstream>
#include"linearList.h"
#include"myExceptions.h"
template<typename T>
class arrayList : public linearList<T> {
private:
	int size;
	int capacity;
	T* element;
	void changeLength(int newCapacity);
public:
	arrayList(int initialCapacity = 10) {
		if (initialCapacity < 0) {
			ostringstream s;
			s << "inilialCapacity = " << initialCapacity << " must be > 0";
			throw illegalParameterValue(s.str());
		}
		capacity = initialCapacity;
		element = new T[capacity]; 
		size == 0;
	}
	arrayList(const arrayList<T>* theList) {
		size = theList->size;
		capacity = theList->capacity;
		element = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			element[i] = theList->element[i];
		}
	}
	~arrayList() { delete[] element; }
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	T get(int theIndex)const;
	void add(int theIndex, const T& theElement);
	T remove(int theIndex);
	void output(ostream& out)const;
};
template<typename T>
T arrayList<T>::get(int theIndex)const {
	if (theIndex<0||theIndex>=size)
	{
		ostringstream s;
		s << "the index = " << theIndex << " must be >= 0 and <size";
		throw illegalParameterValue(s.str());
	}
	return element[theIndex];
}
template<typename T>
void arrayList<T>::changeLength(int newCapacity) {
	T* temp = new T[newCapacity];
	for (int i = 0; i < size; i++) {
		temp[i] = element[i];
	}
	delete[]element;
	element = temp;
	capacity = newCapacity;
}
template<typename T>
void arrayList<T>::add(int theIndex, const T& theElement) {
	if (theIndex<0 || theIndex>size) {
		ostringstream s;
		s << "theIndex: = " << theIndex << " must be >=0 and <= size";
		throw illegalParameterValue(s.str());
	}
	if (size == capacity) {
		changeLength(2 * capacity);
	}
	for (int i = size - 1; i > theIndex - 1; i--) {
		element[i + 1] = element[i];
	}
	element[theIndex] = theElement;
	size++;
}
template<typename T>
T arrayList<T>::remove(int theIndex) {
	if (theIndex < 0 || theIndex >= size) {
		throw illegalParameterValue("illegal index");
	}
	if (size < capacity / 4) {
		changeLength(capacity / 2);
	}
	for (int i = index + 1; i < size; i++) {
		element[i - 1] = element[i];
	}
	element[size - 1] = NULL;
	size--;
}
template<typename T>
void arrayList<T>::output(ostream& out)const {
	out << "size: " << size << ", capacity: " << capacity <<", [";
	for (int i = 0; i < size; i++) {
		out<<element[i]<<" "
	}
	out << "]" << endl;
}
template<typename T>
ostream& operator<<(ostream& out, const arrayList<T>& x) {
	x.output(out); return out;
}