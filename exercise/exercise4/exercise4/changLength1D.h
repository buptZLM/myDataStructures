#pragma once
#include "myException.h"

using namespace std;

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	if (newLength < 0)
		throw illegalParamentValue("new length must be >= 0");

	T* temp = new T[newLength];              // new array
	int number;// number to copy
	if (oldLength < newLength)
		number = oldLength;
	else
		number = newLength;
	copy(a, a + number, temp);
	delete[] a;                             // deallocate old memory
	a = temp;
}