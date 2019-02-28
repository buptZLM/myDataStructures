#pragma once
#include<iostream>
template<typename T>
class linearList
{
public:
	virtual ~linearList()
    virtual bool empty()const = 0;
	virtual int size()const = 0;
	virtual T& get(int theIndex)const = 0;
	virtual int indexOf(const T& theIndex)const = 0;
	virtual void insert(int theIndex, const T& theElement) = 0;
	virtual void erase(int theIndex) = 0;
	virtual void output(std::ostream& out)const = 0;

};