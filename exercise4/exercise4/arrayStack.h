#pragma once
#include"changLength1D.h"
#include"myException.h"
#include"stack.h"
#include<sstream>
template<typename T>
class arrayStack :public stack<T>
{
private:
	int stackSize;
	int stackLength;
	T* stack;
public:
	arrayStack(int initialCapacity=10);
	~arrayStack() { delete[]stack; }
	bool empty()const { return stackSize == 0; }
	int getSize()const { return stackSize; }
	T& top()const {
		if (stackSize == 0)
			throw stackEmpty(); 
	}
	void pop() {
		if (stackSize == 0)
			throw stackEmpty();
		stack[stackSize-1].~T();
		stackSize--;
	}
	void push(const T& theElement);
	void output(ostream& out)const;
};
template<typename T>
arrayStack<T>::arrayStack(int initialCapacity) {
	if (initialCapacity < 1) {
		ostringstream s;
		s << "initial capacity = " << initialCapacity << " must be > 0";
		throw illegalParamentValue(s.str());
	}
	stackLength = initialCapacity;
	stack = new T[stackLength];
	stackSize = 0;
}


template<typename T>
void arrayStack<T>::push(const T& theElement) {
	if (stackSize == stackLength) {
		changeLength1D(stack, stackLength, 2 * stackLength);
	}
	stack[stackSize] = theElement;
	stackSize++;
}

template<typename T>
void arrayStack<T>::output(ostream& out)const {
	out << "StackSize: " <<stackSize<< " StackCapacity: " << stackLength;
	out << "Stack: [";
	for (int i = 0; i < stackSize; i++) {
		out << stack[i];
		if (i != stackSize - 1)
			cout << ", ";
	}
	out << " ] top" << endl;
	out << stack[stackSize];
}

template<typename T>
ostream& operator<<(ostream& out, const arrayStack<T>& x) {
	x.output(out); return out;
}