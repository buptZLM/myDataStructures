#pragma once
#include"chainNode.h"
#include"linearList.h"
#include"myExceptions.h"
template<typename T>
class chainList :public linearList<T>
{
private:
	chainNode<T>* dummyHead;
	int size;
public:
	chainList() {
		size = 0;
		dummyHead = new chainNode<T>;
	}
	chainList(const chainList<T>& theList);
	bool empty() { return size == 0; }
	int getSize() { return size; }
	void add(int x, const T& theElement);
	T remove(int theIndex);
	void output(ostream& out)const;
};
template<typename T>
chainList<T>::chainList(const chainList<T>& theList) {
	size = theList.size;
	chainNode<T>* res = theList.dummyHead;
	dummyHead = new chainNode<T>(res->element, res->next);
	chainNode<T>* tar = dummyHead;
	while (res->next!=nullptr)
	{
		res = res->next;
		tar->next = new cahinNode<T>(res->element, res->next);
		tar = tar->next;
	}
}
template<typename T>
void chainList<T>::add(int theIndex, const T& theElement) {
	if (index<0 || index>size) {
		throw illegalParameterValue("illegal Index");
	}
	chainNode<T>* prev = dummyHead;
	for (int i = 0; i < theIndex; i++) {
		prev = prev->next;
	}
	prev->next = new chainNode<T>(theElement, prev->next);
	size++;
}
template<typename T>
T chainList<T>::remove(int theIndex) {
	if (theIndex < 0 || theIndex >= size) {
		throw illegalParameterValue("illegal index");
	}
	chainNode<T>* prev = dummyHead;
	for (int i = 0; i < theIndex; i++) {
		prev = prev->next;
	}
	chainNode<T>* deleteNode = prev->next;
	prev->next = deleteNode->next;
	T e = deleteNode->element;
	delete deleteNode;
	size--;
	return e;
}
template<typename T>
void chainList<T>::output(ostream& out)const {
	out << "size: " << size << " [";
	chainNode<T>* cur = dummyHead->next;
	while (cur != nullptr) {
		out << cur->element;
		cur = cur->next<<" ";
	}
	out << "]" << endl;
}
template<typename T>
ostream& operator<<(ostream& out, const chainList<T>& x) {
	x.output(out);
	return out;
}