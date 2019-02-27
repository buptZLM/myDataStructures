#pragma once
#include<iostream>
#include"stack.h"
#include"changeLength1D.h"
#include"myExceptions.h"
using namespace std;
template<typename T>
class arrayStack :public stack<T>
{
private:
	int size;
	int capacity;
	T* element;
public:
	arrayStack(int initialCapacity = 10);
	~arrayStack() {
		delete[] element;
	}
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	T& top()const {
		if (size == 0)
			throw stackError();
		return element[size - 1]; 
	}
	void push(const T& theElement) {
		if (size == capacity) {
			changeLength1D(element, capacity, 2 * capacity);
			capacity *= 2;
		}
		element[size++] = theElement;
	}
	void pop() {
		if (size == 0)
			throw stackError();
		element[size - 1].~T();
		size--;
	}
};
template<typename T>
arrayStack<T>::arrayStack(int initialCapacity){
	if (initialCapacity < 0)
		throw illeaglParameterValue("initial capacity must be > 0");
	size = 0;
	capacity = initialCapacity;
	element = new T[capacity];
}
