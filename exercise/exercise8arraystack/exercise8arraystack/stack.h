#pragma once
#include<iostream>
using namespace std;
template<typename T>
class stack
{
public:

	virtual ~MyClass() {};
	virtual bool empty()const = 0;
	virtual int getSize()const = 0;
	virtual T& top()const = 0;
	virtual void push(const T& theElement) = 0;
	virtual void pop() = 0;
};

