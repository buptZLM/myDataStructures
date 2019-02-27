#pragma once
#include<iostream>
#include"Queue.h"
#include"arrayList.h"
using namespace std;
template<typename T>
class arrayQueue :public queue<T>
{
private:
	arrayList<T> arr;
public:
	arrayQueue() {};
	arrayQueue(int initialCapacity) :arr(initialCapacity) {};
	int getSize()const { return arr.getSize(); }
	bool empty()const { return arr.empty(); }
	int getCapacity()const { return arr.getCapacity(); }
	void enqueue(const T& e) { arr.addLast(e); }
	void dequeue() { arr.removeFirst(); }
	void output(ostream& out)const;
	T& getFront()const { return arr.getFirst(); }

};
template<typename T>
void arrayQueue<T>::output(ostream& out)const {
	out << "queueSize: " << arr.getSize() << " queueCapacity: " << arr.getCapacity();
	out << "Front: [";
	for (int i = 0; i < arr.getSize(); i++) {
		out << arr.get(i);
		if (i != arr.getSize() - 1)
			cout << ", ";
	}
	out << " ] Last" << endl;
}

template<typename T>
ostream& operator<<(ostream& out, const arrayQueue<T>& x) {
	x.output(out); return out;
}