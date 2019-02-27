#pragma once
#include"myExceptions.h"
template<typename T>
void changeLength1D(T* &a, int oldLength, int newLength)
{
	if (newLength < 0) {
		ostringstream s;
		throw illegalParameterValue("new length must be > 0");
	}
	int len;
	if (oldLength < newLength)
		len = oldLength;
	else
		len = newLength;
	T *temp = new T[newLength];
	for (int i = 0; i < len; i++) {
		temp[i] = a[i];
	}
	delete a;
	a = temp;		
}