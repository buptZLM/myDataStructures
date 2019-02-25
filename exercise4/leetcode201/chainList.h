#pragma once
#include"chainNode.h"
template<typename T>
class chainList
{
private:
	chainNode<T>* dummyHead;
	int size;
public:
	chainList() {
		size = 0;
		dummyHead = new chainNode<T>;
	}
	chainList(const chainList<T>& theNode) {
		size == theNode.size;
		chainNode<T>* sourceNode = theNode.dummyHead;
		dummyHead = new chainNode<T>(sourceNode->element);
		chainNode<T>* targetNode = dummyHead;
		sourceNode = sourceNode->next;
		while (sourceNode!=nullptr)
		{
			targetNode->next = new chainNode<T>(sourceNode->element);
			sourceNode = sourceNode->next;
			targetNode = targetNode->next;
		}
	}
	~chainList() { delete dummyHead; }
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	int findElement(chainNode<T>* Head, T& E) {
		static int i = 0;
		if (head == nullptr)
			return 10;
		int res = findElement(Head->next, E);
		if (Head->element == E) {
			return i;
		}
		else {
			i=1+ res;
			return i;
		}
	}
	int find(const T& theElement)const {
		return findElement(dummyHead->next, theElement);
	}
	
};