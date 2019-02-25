#pragma once
#include<iostream>
#include"Queue.h"
#include"myExceptions.h"
using namespace std;
template<typename T>
class loopQueue:public queue<T>
{
private:
	T * element;
	int front, tail;
	int capacity;
	int size;
public:
	loopQueue(int initialCapacity=10) {
		capacity = initialCapacity;
		element = new T[capacity + 1];
		front = 0;
		tail = 0;
		size = 0;
	}
	int getCapacity()const {
		return capacity;
	}
	bool empty()const {
		return front == tail;
	}
	int getSize()const {
		return size;
	}
	void enqueue(const T& e) {
		if ((tail + 1) % (capacity+1) == front)
			resize(capacity * 2);
		element[tail] = e;
		tail = (tail + 1) % capacity;
		size++;
	}
	void dequeue() {
		if (empty())
			throw illegalParameterValue("the queue is empty");
		//T ret = element[front];
		element[front] = NULL;
		front = (front + 1) % capacity;
		size--;
		if (size == capacity / 4 && capacity / 2 != 0)
			resize(capacity / 2);
		//return ret;
	}
	T& getFront()const {
		if (empty())
			throw illegalParameterValue("the queue is empty");
		return element[front];
	}
	void resize(int newCapacity) {
		T* temp = new T[newCapacity + 1];
		for (int i = 0; i < size; i++)
			temp[i] = element[(front + i) % capacity];
		delete[]element;
		element = temp;
		front = 0;
		tail = size;
		capacity = newCapacity;
	}

	void output(ostream& out)const {
		out << "queueSize: " << getSize() << " queueCapacity: " << getCapacity();
		out << "front: [";
		for (int i = front; i != tail; i=(i+1)%(capacity +1)){
			out <<element[i];
			if (i != tail - 1)
				cout << ", ";
		}
		out << " ] top" << endl;
	}

};

template<typename T>
ostream& operator<<(ostream& out, const loopQueue<T>& x) {
	x.output(out); return out;
}