#pragma once
#include<iostream>
#include"Queue.h"
#include"myException.h"
template<typename T>
class loopQueue :public queue<T>
{
private:
	int size;
	int capacity;
	int front, tail;
	T* element;
public:
	loopQueue(int initialCapacity = 10) {
		if (initialCapacity < 0)
			throw illegalParamentValue("initial capacity must be > 0");
		size = 0; capacity = initialCapacity;
		front = tail = 0;
		element = new T[capacity + 1];
	}
	loopQueue(const loopQueue<T>& x) {
		size = x.size;
		capacity = x.capacity;
		front = x.front;
		tail = x.tail;
		element = new T[capacity+1];
		for (int i = front; i != tail; i = (i + 1) % (capacity + 1)) {
			element[i] = x.element[i];
		}
	}
	~loopQueue() { delete[]element; }
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	int getCapacity()const { return capacity; }
	T& getFront()const { return element[front]; }
	void enqueue(const T& e) {
		if ((tail + 1) % (capacity + 1) == front)
			resize(2 * capacity);
		element[tail] = e;
		tail = (tail + 1) % (capacity + 1);
		size++;
	}
	T dequeue() {
		T ret = element[front];
		if (size == capacity / 4) {
			resize(capacity / 2);
		}
		element[front] = NULL;
		front = (front + 1) % (capacity + 1);
		size--;
		return ret;
		
	}
	void resize(int newCapacity) {
		if (newCapacity <= 0)
			throw illegalParamentValue(" new capacity must be > 0");
		T* temp = new T[newCapacity+1];
		for (int i = 0; i < size; i++) {
			temp[i] = element[(i + front) % (capacity + 1)];
		}
		delete[]element;
		element = temp;
		capacity = newCapacity;
		front = 0;
		tail = size;
	}
	void output(ostream& out)const {
		out << "QueueSize = " << size << " Capacity = " << capacity << " front: [ ";
		for (int i = front; i!=tail; i = (i + 1) % (capacity + 1)) {
			out << element[i];
			if ((i + 1) % (capacity + 1) != tail) {
				out << ", ";
			}
		}
		out << " ] tail" << endl;
	}
};
template<typename T>
ostream& operator<<(ostream& out, const loopQueue<T>& x) {
	x.output(out);
	return out;
}
