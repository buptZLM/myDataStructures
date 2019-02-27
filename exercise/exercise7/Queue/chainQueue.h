#pragma once
#include<iostream>
#include"Queue.h"
#include"chainNode.h"
#include"myExceptions.h"
using namespace std;
template<typename T>
class chainQueue:public queue<T>
{
public:
	chainQueue() { size = 0; front = tail = nullptr; }
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	void enqueue(const T& e);
	void dequeue();
	T& getFront()const;
	void output(ostream& out)const;
private:
	int size;
	chainNode<T>* front;
	chainNode<T>* tail;
};
template<typename T>
void chainQueue<T>::enqueue(const T& e) {
	if (tail == nullptr) {
		tail = new chainNode<T>(e);
		front = tail;
	}
	else
	{
		tail->next = new chainNode<T>(e);
		tail = tail->next;
	}
	size++;
}
template<typename T>
void chainQueue<T>::dequeue() {
	if (empty())
		throw illegalParameterValue("the stack is empty");
	chainNode<T>* ret = front;
	front = front->next;
	if (front == nullptr)
		tail = nullptr;
	ret->next = nullptr;
	delete[] ret;
	size--;	
}
template<typename T>
T& chainQueue<T>::getFront()const {
	if (empty())
		throw illegalParameterValue("the stack is empty");
	return front->element;
}
template<typename T>
void chainQueue<T>::output(ostream& out)const {
	out << "front:[ ";
	chainNode<T>* cur = front;
	while (cur!=nullptr)
	{
		out << cur->element<<"->";
		cur = cur->next;
	}
	out << "NULL ] tail";
}
template<typename T>
ostream& operator<<(ostream& out, const chainQueue<T>& x) {
	x.output(out);
	return out;
}