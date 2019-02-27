#pragma once
#include<iostream>
#include"myExceptions.h"
using namespace std;
template<typename T>
void changeLength1D(T* & theElement, int oldLength, int newLength) {
	if (newLength < 0)
		throw illeaglIndexValue();
	T *temp = new T[newLength];
	int len;
	if (newLength > oldLength)
		len = oldLength;
	else
		len = newLength;
	for (int i = 0; i < len; i++) {
		temp[i] = theElement[i];
	}
	delete[] theElement;
	theElement = temp;
}