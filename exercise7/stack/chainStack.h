#pragma once
#include<iostream>
#include"stack.h"
#include"chainList.h"
template<typename T>
class chainStack: public stack<T>
{
private:
	chain<T> list;
public:
	chainStack(int initialCapacity = 10) :list(initialCapacity) {};
	bool empty()const { return list.empty();}
	int getSize()const { return list.getSize(); }
	T& top()const { return list.getFirst(); }
	void push(const T& theElement) { list.addFirst(theElement); }
	void pop() { list.removeFirst(); }
	void output(ostream& out)const {
		out << "stack top: "<<list;	
	}
};
template<typename T>
ostream& operator<<(ostream& out, const chainStack<T>& x) {
	x.output(out);
	return out;
}