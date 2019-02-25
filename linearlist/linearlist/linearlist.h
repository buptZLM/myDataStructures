#pragma once
#ifndef linearlist
#define linearlist
#include<iostream>
using namespace std;
/*
template<class T>
class linearlist
{
public:
	virtual ~linearlist() {};
	virtual bool empty() const = 0;
	virtual int size()const = 0;
	virtual T& get(int theIndex) const = 0;
	virtual int indexof(const T& theElement)const = 0;
	virtual void erase(int theIndex) = 0;
	virtual void insert(int theIndex, const T& theElement) = 0;
	virtual void output(ostream & out)const = 0;
};
*/
template<class T>
class arraylist// : public linearlist<T>
{
protected:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	void checkIndex(int theIndex)const;
	T* element;
	int arrayLength;
	int listSize;
public:
	//构造函数，复制构造函数，析构函数
	arraylist(int initialCapacity = 10);
	arraylist(const arraylist<T>&);
	~arraylist() { delete[]element; }

	//方法
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexof(const T& theElement)const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream & out)const;
	int capacity()const { return arrayLength; }
};

template<class T>
void changeLengthID(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		cout<<"new length must be >0";
	T* temp = new T[newLength];
	//int number = min(oldLength, newLength);
	int number;
	if (oldLength > newLength)
		number = newLength;
	else number = oldLength;
	copy(a, a + number, temp);
	delete[]a;
	a = temp;

}

#endif // !linearlist
