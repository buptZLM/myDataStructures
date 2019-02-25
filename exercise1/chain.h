#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"linearList.h"
#include"chainNode.h"
#include"myExceptions.h"
template<typename T>
class chain : public linearLinst<T>
{
public:
	chain(int initialCapacity=0);
	chain(chain<T>& theList);
	~chain();
	virtual bool empty()const { return listSize == 0; }
	virtual int size()const { return listSize; }
	virtual T& get(int theIndex)const;
	virtual int indexOf(const T& theElement)const;
	virtual void erase(int theIndex);
	virtual void insert(int theIndex, const T& theElement);
	virtual void output(ostream& out)const;
	class iterator;
	iterator begin() { return iterator(firstNode); }
	iterator end() { return iterator(nullptr); }
	class iterator
	{
	public:
		iterator(chainNode<T>* theNode = nullptr) { node=theNode; }

		T& operator*()const { return node->element; }
		T* operator->()const { return &node->element; }

		iterator& operator++()
		{
			node =node->next; return*this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			node = node->next;
			return old;
		}
		bool operator!=(const iterator right)const
		{
			return node != right.node;
		}
		bool operator==(const iterator right)const
		{
			return node == right.node;
		}
	private:
		chainNode<T>* node;
	};
protected:
	int listSize;
	chainNode<T>* firstNode;
	void checkIndex(int theIndex)const;
};

template<typename T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity < 0) {
		ostringstream s;
		s << "initialCapacaty = " << initialCapacity << " must be > 0 ";
		throw illegalParameterValue(s.str());
}
	firstNode = nullptr;
	listSize = 0;
}
template<typename T>
chain<T>::chain(chain<T>& theList)
{
	listSize = theList.listSize;
	if (listSize == 0)
	{
		firstNode = nullptr;
		return;
	}
	
	chainNode<T>*sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	chainNode<T>*targetNode = firstNode;
	sourceNode = sourceNode->next;
	while (sourceNode != nullptr) {
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = nullptr;
}
template<typename T>
chain<T>::~chain()
{
	while (firstNode!=nullptr)
	{
		chainNode<T>* temp = firstNode;
		firstNode = firstNode->next;
		delete temp;
	}
}
template<typename T>
void chain<T>::checkIndex(int theIndex) const
{
	if (theIndex<0 || theIndex>listSize - 1)
	{
		ostringstream s;
		s << "theIndex = " << theIndex << " listSize = " << listSize;
		throw illegalIndex(s.str());
	}
}
template<typename T>
T& chain<T>::get(int theIndex)const
{
	checkIndex(theIndex);
	chainNode<T>*p = firstNode;
	for (int i = 0; i < theIndex; i++)
	{
		p = p->next;
	}
	return p->element;
}

template<typename T>
int chain<T>::indexOf(const T & theElement)const
{
	chainNode<T>* p = firstNode;
	int theIndex = 0;
	while (p != nullptr && p->element !=theElement)
	{ 
		p = p->next;
		theIndex++;
	}
	if (p == nullptr)
		return -1;
	return theIndex;
}
template<typename T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	chainNode<T>*currentNode = firstNode;
	chainNode<T>*deleteNode;
	if (theIndex == 0)
	{
		deleteNode = firstNode;
		firstNode = firstNode->next;
	}
	else
	{
		for (int i = 0; i<theIndex - 1; i++)
		{
			currentNode = currentNode->next;
		}
		deleteNode = currentNode->next;
		currentNode->next = deleteNode->next;
	}
	delete deleteNode;
	listSize--;
}
template<typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		ostringstream s;
		s << "theIndex = " << theIndex << " listSize = " << listSize;
		throw illegalIndex(s.str());
	}
	if (theIndex == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
	}
	else
	{
		chainNode<T>*currentNode = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
			currentNode = currentNode->next;		
		currentNode->next = new chainNode<T>(theElement, currentNode->next);
	}
	
	listSize++;
}
template<typename T>
void chain<T>::output(ostream& out)const
{
	for (chainNode<T>* currentNode = firstNode;currentNode != nullptr;
		currentNode = currentNode->next)
	{
		out << currentNode->element << " ";
	}
}
template<typename T>
ostream& operator<<(ostream& out,const chain<T>& x)
{
	x.output(out);
	return out;
}