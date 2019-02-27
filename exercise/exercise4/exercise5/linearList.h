#pragma once
#include<iostream>
using namespace std;
template<typename T>
class linearList
{
	virtual linearList() {};
	virtual bool empty()const = 0;
	virtual int getSize()const = 0;
	virtual T get(int theIndex)const = 0;
	virtual void add(int theIndex, const T& theElement)= 0;
	virtual T remove(int theIndex) = 0;
	virtual void output(ostream & out)const = 0;
};