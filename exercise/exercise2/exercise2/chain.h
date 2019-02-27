#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"linearList.h"
#include"myExceptions.h"
#include"chainNode.h"
using namespace std;
template<class T>
class chain:public linearList<T>
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
	void output(ostream & out)const;

	class iterator;
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(nullptr); }
	class iterator
	{
	private:
		chainNode<T>* node;
	public:
		iterator(chainNode<T>* theNode = nullptr) { node=theNode; }

		T& operator*()const { return node->element; }
		T* operator->()const { return &node->element; }

		iterator& operator++(int) {
			node = node->next;
			return *this;
		}
		iterator operator++(int) {
			iterator old = *this;
			node = node->next;
			return old;
		}
	};
	bool operator!=(const iterator right)const {
		return node != right.node;
	}
	bool operator==(const iterator right)const {
		return node == right.node;
	}
};
template<typename T>
chain<T>::chain(int initialCapacity) {
	if (initialCapacity < 0) {
		ostringstream s;
		s << " initialCapacity = " << initialCapacity << "must be > 0";
		throw illegalParameterValue(s.str());
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
		firstNode = new chainNode<T>(sourceNode->element);
		chainNode<T>* targetNode = firstNode;
		sourceNode = sourceNode->next;
		while (sourceNode != nullptr) {
			targetNode->next = new chainNode<T>(sourceNode->element);
			sourceNode = sourceNode->next;
			targetNode = targetNode->next;
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
void chain<T>::checkIndex(int theIndex)const {
	if (theIndex<0 || theIndex>listSize - 1) {
		ostringstream s;
		s << "illegal index";
		throw illegalIndex(s.str());
	}
}
template<typename T>
T& chain<T>::get(int theIndex)const {
	checkIndex(theIndex);
	chainNode<T>*p=firstNode;
	for (int i = 0; i < theIndex; i++) {
		p = p->next;
	}
	return p->element;
}
template<typename T>
int chain<T>::indexOf(const T& theElement)const {
	chainNode<T>*p = firstNode;
	int theIndex = 0;
	while (p!=nullptr&&p->element!=theElement)
	{
		p = p->next;
		theIndex++;
	}
	return theIndex;
}
template<typename T>
void chain<T>::insert(int theIndex, const T& theElement) {
	if (theIndex<0 || theIndex>listSize) {
		ostringstream s;
		s << "illegal index";
		throw illegalIndex(s.str());
	}
	if (theIndex == 0) {
		firstNode = new chainNode<T>(theElement, firstNode);
	}
	else
	{
		chainNode<T>*currentNode = firstNode;
		for (int i = 0; i < theIndex - 1; i++) {
			currentNode = currentNode->next;
		}
		currentNode->next = new chainNode<T>(theElement, currentNode->next);
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
		out << p->element<<" ";
		p = p->next;
	}
}
template<typename T>
ostream& operator<<(ostream& out, chain<T>& x) {
	x.output(out);
	return out;
}