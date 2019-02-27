#pragma once
#include<iostream>
#include"stack.h"
#include"arrayList.h"
#include"myExceptions.h"
template<typename T>
class arrayStack :public stack<T>
{
private:
	arrayList<T> arr;
public:
	arrayStack() {};     //将使用arrayList默认的构造函数初始化arr
	arrayStack(int initialCapacity) :arr(initialCapacity) {};
	bool empty()const { return arr.empty(); }
	int getSize()const { return arr.getSize(); }
	int getCapacity()const { return arr.capacity(); }
	T& top()const { return arr.getLast(); }
	void push(const T& theElement) { arr.addLast(theElement); }
	void pop() { arr.removeLast(); }
	void output(ostream& out)const;
};
template<typename T>
void arrayStack<T>::output(ostream& out)const {
	out << "StackSize: " << arr.getSize() << " StackCapacity: " << arr.getCapacity();
	out << "Stack: [";
	for (int i = 0; i < arr.getSize(); i++) {
		out << arr.get(i);
		if ( i != arr.getSize() - 1)
			cout << ", ";
	}
	out << " ] top"<<endl;
}

template<typename T>
ostream& operator<<(ostream& out, const arrayStack<T>& x) {
	x.output(out); return out;
}