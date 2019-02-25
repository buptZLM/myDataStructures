#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"linearList.h"
#include"myExceptions.h"
#include"chainNode.h"
using namespace std;
template<typename T>
class chain:public linearList
{
private:
	int listSize;
	chainNode<T>* firstNode;
	void checkIndex(int theIndex)const;
public:
	chain(int initialCapacity = 0);
	chain(chain<T>& theList);
	~chain();

	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void insert(int theIndex, const T& theElement);
	void erase(int theIndex);
	void output(ostream& out)const;

};
template<typename T>
chain<T>::chain(int initialCapacity) {
	if (initialCapacity < 0) {
		ostringstream s;
		s << "initialCapacity must be > 0";
		throw illegalParamentValue(s.str());
	}
	listSize = 0;
	firstNode = nullptr;
}
template<typename T>
chain<T>::chain(chain<T>& theList) {
	listSize = theList.listSize;
	if (listSize == 0) {
		firstNode = nullptr;
	}
	else
	{
		chainNode<T>* sourceNode = theList.firstNode;
		chainNode<T>* targetNode = new chainNode<T>(sourceNode->element);
		firstNode = targetNode;
		sourceNode = sourceNode->next;
		while (sourceNode != nullptr) {
			targetNode->next = new chainNode<T>(sourceNode->element);
			targetNode = targetNode->next;
			sourceNode = sourceNode->next;
		}
		targetNode->next = nullptr;
	}
}
template<typename T>
chain<T>::~chain() {
	while (firstNode != nullptr) {
        chainNode<T>* p = firstNode;
		firstNode = firstNode->next;
		delete p;
	}
}
template<typename T>
T& get(int theIndex)const {
	checkIndex(theIndex);
	chainNode<T>* p = firstNode;
	for (int i = 0; i < theIndex; i++) {
		p = p->next;
	}
	return p->element;
}
template<typename T>
int indexOf(const T& theElement)const {
	chainNode<T>* p = firstNode;
	int theIndex=0;
	while (p->element != theElement && p != nullptr) {
		p = p->next;
		theIndex++;
	}
	if (p == nullptr)
		return -1;
	else
	{
		return theIndex;
	}
}
template<typename T>
void chain<T>::insert(int theIndex, const T& theElement) {
	if (theIndex<0 || theIndex>listSize) {
		ostringstream s;
		s << "illegal Index";
		throw illegalIndex(s.str());
	}
	if (theIndex == 0) {
		fisrtNode = new chainNode<T>(firstNode->element);
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++) {
			p = p->next;
		}
		p->next = new chainNode<T>(theElement, p->next);
	}
	listSize++;
}
template<typename T>
void chain<T>::erase(int theIndex) {
	checkIndex(theIndex);
	chainNode<T>* deleteNode;
	if (theIndex == 0) {
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++) {
			p = p->next;
		}
		deleteNode = p->next;
		p->next = deleteNode->next;
	}
	delete deleteNode;
	listSize--;
}
template<typename T>
void chain<T>::output(ostream& out)const {
	chainNode<T>* p = firstNode;
	while (p!=nullptr)
	{
		cout << p->element << " ";
		p = p->next;
	}
}
template<class T>
ostream& operator<<(ostream& out, chain<T>& x) {
	x.output(out);
	return out;
}

