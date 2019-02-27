#pragma once
#include"Queue.h"
#include"changLength1D.h"
#include"myException.h"
using namespace std;
template<typename T>
class arrayQueue :public queue<T>
{
private:
	int size;
	int capacity;
	T* element;
public:
	arrayQueue(int initialCapacity=10) {
		capacity = initialCapacity;
		size = 0;
		element = new T[capacity];
	};
	arrayQueue(const arrayQueue<T>& x);
	~arrayQueue() { delete[] element; }
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	int getCapacity()const { return capacity; }
	T& getFront()const { return element[size - 1]; }
	void enqueue(const T& theElement);
	T dequeue();
	void output(ostream& out)const;
	void resize(const int newCapacity);
};
template<typename T>
arrayQueue<T>::arrayQueue(const arrayQueue<T>& x) {
	size = x.size;
	capacity = x.capacity;
	element = new T[capacity];
	for (int i = 0; i < size; i++) {
		element[i] = x.element[i];
	}
}
template<typename T>
void arrayQueue<T>::resize(const int newCapacity) {
	if (newCapacity <= 0)
		throw illegalParamentValue("newCapacity must be > 0");
	T*temp = new T[newCapacity];
	for (int i = 0; i < size; i++) {
		temp[i] = element[i];
	}
	delete[]element;
	element = temp;
}
template<typename T>
void arrayQueue<T>::enqueue(const T& theElement) {
	if (size == capacity) {
		resize(2 * capacity);
		capacity *= 2;
	}
	element[size++] = theElement;
}
template<typename T>
T arrayQueue<T>::dequeue() {
	if (size == capacity / 4) {
		resize(capacity / 2);
		capacity = capacity / 2;
	}
	T ret = element[0];
	for (int i = 1; i < size; i++) {
		element[i - 1] = element[i];
	} 
	element[size - 1].~T();
	size--;
	return ret;
}
template<typename T>
void arrayQueue<T>::output(ostream& out)const {
	out << "QueueSize = " << size << "  Capacity = " << capacity<<" front: [ ";
	for (int i = 0; i < size; i++) {
		out << element[i];
		if(i!=size-1)
		   out<<", ";
	}
	out << " ]"<<endl;
}
template<typename T>
ostream& operator<<(ostream& out, arrayQueue<T>& x) {
	x.output(out);
	return out;
}
