#pragma once
#include"myExceptions.h"
#include<algorithm>
template<class T>
class Array
{
private:
	int size;
	int capacity;
	T *element;
	void checkIndex(int theIndex)const;
public:
	Array(int initialCapacity = 10);
	Array(const Array<T>&);
	~Array() { delete[] element; }

	int getSize()const { return size; }
	int getCapacity()const { return capacity; }
	bool empty() { return size == 0; }
	T& get(int index)const;
	int find(const T& theElement)const;
	void findAll(const T& theElement)const;
	void insert(int index, const T& theElement);
	void erase(const T& theElement);
	void eraseAll(const T& theElement);
	void changeLength1D(T*& a, int oldLength, int newLength);
	void output(ostream& out)const;
};
template<class T>
Array<T>::Array(int initialCapacity) {
	if (initialCapacity<0)
	{
		ostringstream s;
		s << "initial capacity = " << initialCapacity << " must be >0 " << endl;
		throw illegalParameterValue(s.str());
	}
	capacity = initialCapacity;
	size = 0;
	element = new T[capacity];
}
template<class T>
Array<T>::Array(const Array<T>& x) {
	capacity = x.capacity;
	size = x.size;
	element = new T[capacity];
	for (int i = 0; i < size; i++)
		element[i] = x.element[i];
}

template<class T>
void Array<T>::checkIndex(int theIndex)const {
	if (theIndex < 0 || theIndex >= size) {
		ostringstream s;
		s << "theIndex = " << theIndex << " must be >0 " << endl;
		throw illegalParameterValue(s.str());
	}
}
template<class T>
T& Array<T>::get(int index)const {
	checkIndex(index);
	return element[index];
}
template<class T>
int Array<T>::find(const T& theElement)const {
	int res;
	for (int i = 0; i < size; i++) {
		if (element[i] == theElement)
			return i;
	}
		return -1;
}
template<class T>
void Array<T>::findAll(const T& theElement)const {
	for (int i = 0; i < size; i++) {
		if (element[i] == theElement)
			cout << i << " ";
	}
	cout << endl;
}
template<class T>
void Array<T>::insert(int index, const T& theElement) {
	if (index<0 || index>size) {
		ostringstream s;
		s << "index = " << index << " must be index>=0 or index<=size" << endl;
		throw illegalParameterValue(s.str());
	}
	//if(size==capacity)
	if (size == capacity) {
		changeLength1D(element, capacity, 2 * capacity);
		capacity *= 2;
	}
	if (size == 0) {
		element[index] = theElement;
	}
	else
	{
		for (int i = size; i > index; i--) {
				element[i] = element[i - 1];
			}
			element[index] = theElement;
	}
	size++;
}

template<class T>
void Array<T>::erase(const T& theElement) {
	int index = find(theElement);
	if (index < 0)
		cout << "theElement not found" << endl;
	else
	{
		for (int i = index + 1; i < size; i++)
			element[i - 1] = element[i];
	}
	size--;
	if (size < (capacity / 2)) {
		changeLength1D(element, capacity,( capacity / 2));
		capacity = capacity / 2;
	}
}

template<class T>
void Array<T>::eraseAll(const T& theElement) {
	while (find(theElement) >= 0)
		erase(theElement);
}

template<class T>
void Array<T>::changeLength1D(T*& a, int oldLength, int newLength) {
	if (newLength < 0) {
		ostringstream s;
		s << "newLength = " << newLength << " must be >0" << endl;
		throw illegalParameterValue(s.str());
	}
	int L=min(oldLength,newLength);


	T* temp = new T[L];
	for (int i = 0; i < size; i++) {
		temp[i] = a[i];
	}
	delete []a;
	a = temp;
}

template<class T>
void Array<T>::output(ostream& out)const {
	out << "capacity = " << capacity << endl;
	out << "size = " << size << endl;
	out << "the element are [";
	for (int i = 0; i < size; i++) {
		out << element[i];
	}
	out << "]" << endl;
}
template<class T>
ostream& operator<<(ostream& out, Array<T> & x) {
	x.output(out);
	return out;
}


