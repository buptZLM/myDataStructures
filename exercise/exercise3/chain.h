#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"linearList.h"
#include"chainNode.h"
#include"myException.h"
using namespace std;
template<typename T>
class chain:public linearList<T>
{
public:
	chain(int initialCapacity);
	chain(chain<T>& theList);
	~chain();
	bool empty()const { return listSize == 0; }
	int size()const { return listSize; }
	T& get(int theIndex)const;
	int indexOf(const T& theElement)const;
	void insert(int theIndex, const T& theElement);
	void erase(int theIndex);
	void output(ostream& out)const;
	class iterator;
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(nullptr); }
	class iterator
	{
	private:
		chainNode<T>* node;
	public:
		iterator(chainNode<T>* theNode = nullptr) { theNode; }
		T& operator*()const { return node->element; }
		T* operator->()const { return &node->element; }
		iterator& operator++(int) {
			node = node->next;
			return *this;
		}
		iterator operator++() {
			chainNode<T>* old = node;
			node = node->next;
			return old;
		}
		bool operator==(const iterator right)const {
			return node == right.node;
		}
		bool operator!=(const iterator right)const {
			return node != righr.node;
		}
	};

private:
	int listSize;
	chainNode<T>* firstNode;
	void checkIndex(int theIndex)const;
};
template<typename T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity<0 || initialCapacity>listSize) {
		ostringstream s;
		s << "illegal value";
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
	else {
		chainNode<T>* sourceNode = theList.firstNode;
		chainNode<T>*targetNode = new chainNode<T>(sourceNode->element);
		sourceNode = sourceNode->next;
		firstNode = targetNode;
		while (sourceNode != nullptr)
		{
			targetNode->next = new chainNode<T>(sourceNode->element);
			sourceNode = sourceNode->next;
			targetNode = targetNode->next;
		}
		targetNode->next = nullptr;
	}
}
template<typename T>
chain<T>::~chain()
{
	while (firstNode != nullptr) {
        chainNode<T>* P = firstNode;
		firstNode = firstNode->next;
		delete P;
	}
}
template<typename T>
T& chain<T>::get(int theIndex)const {
	checkIndex(theIndex);
	chainNode<T>* p = firstNode;
	for (int i = 0; i<theIndex; i++) {
		p = p->next;
	}
	return p->element;
}
template<typename T>
int chain<T>::indexOf(const T& theElement)const {
	int index = 0;
	chainNode<T>* p = firstNode;
	while (p != nullptr&&p->element != theElement) {
		index++;
		p = p->next;
	}
	if (p==nullptr)
	{
		return -1
	}
	else
	{
		return index;
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
		firstNode=new chainNode<T>(theElement,firstNode)
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
		for (int i = 0; i < theIndex - 1; i++)
		{
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
		out << p->element;
		p = p->next;
	}
}
template<typename T>
ostream& operator<<(ostream& out, chain<T>& x) {
	x.output(out);
	return out;
}