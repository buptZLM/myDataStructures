#pragma once
#include <iostream>
#include"linearlist.h"
using std::cout;
using std::endl;
template <class T>
arraylist<T>::arraylist(int initialCapacity)
{
	if (initialCapacity < 1)
	{
	
		cout<< "Initial caapcity=" << initialCapacity << "must be>0";
//		throw illegalParameterValue(cout.str());
//		cout << "initialCapcity=" << initialCapacity << "must be >0";
	}
	arrayLength = initialCapacity;
	element = new T[arrayLength];
	listSize = 0;
}

template<class T>
arraylist<T>::arraylist(const arraylist<T>& thelist)
{
	arrayLength = thelist.arrayLength;
	listSize = thelist.listSize;
	element = new T[arrayLength];
	//copy(thelist.element, thelist.element + listSize, element);
}

template<class T>
void arraylist<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		//ostringstream s;
		//s << "Index=" << theIndex << "size=" << listSize;
		//throw illegalIndex(s.str());
		cout << "illegalIndex";
	}
}
 template<class T>
 T& arraylist<T>::get(int theIndex)const
 {
	 checkIndex(theIndex);
	 return element[theIndex];
 }

 template<class T>
 int arraylist<T>::indexof(const T& theElement)const
 {//返回元素第一次出现时的索引，若无则返回-1
	 //查找该元素，STL
	 int theIndex = (int)(find(element, element + listSize, theElement) - element);

	 //确认theElement是否找到
	 if (theIndex == listSize)
		 return -1;
	 else return theIndex;
 }

 template<class T>
 void arraylist<T>::erase(int theIndex)
 {
	 checkIndex(theIndex);
	// copy(element + theIndex + 1, element + listSize, element + theIndex);
	 for (int i = theIndex + 1; i < listSize; i++)
		 element[i - 1] = element[i];
	// element[--listSize].~T();
 }




 template<class T>
 void arraylist<T>::insert(int theIndex, const T& theElement)
 {
	 if (theIndex<0 || theIndex>listSize)
	 {
		// ostringstream s;
		 cout << "index = " << theIndex << "size = " << listSize;
		// throw illegalIndex(s.str());
	 }
	 if (listSize == arrayLength)
	 {
		 changeLengthID(element, arrayLength, 2 * arrayLength);
		 arrayLength *= 2;
	 }
	for(int i=listSize;i>theIndex;i--)
	 element[i] = element[i-1];
	element[theIndex] = theElement;
	 listSize++;
 }

 template<class T>
 void arraylist<T>::output(ostream& out)const
 {
	 //copy(element, element + listSize, ostream_iterator<T>(out, " "));
	 for (int i = 0; i < listSize; i++)
		 out << element[i];
 }

 template<class T>
 ostream& operator<<(ostream& out, const arraylist<T>& x)
 {
	 x.output(out);
	 return out;
 }

