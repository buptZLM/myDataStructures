#pragma once
#include<sstream>
#include"linearList.h"
#include"myExceptions.h"
#include"chainNode.h"
using namespace std;
template<typename T>
class chain :public linearList<T>
{
private:
	int size;
	chainNode<T>* dummyHead;
	void checkIndex(int index)const;
public:
	chain(int initialCapacity = 0);
	chain(const chain<T>& theList);
	~chain();
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	T& get(int index)const;
	T& getLast()const;
	T& getFirst()const;
	void set(int index, const T& theElement);
	int find(const T& theElement)const;
	void insert(int index, const T& theElement);
	void addFirst(const T& theElement) { insert(0, theElement); }
	void addLast(const T& theElement) { insert(size, theElement); }
	void erase(int index);
	void removeFirst() { erase(0); }
	void removeLast() { erase(size - 1); }
	void output(ostream& out)const;
};
template<typename T>
void chain<T>::checkIndex(int index)const {
	if (index >= size || index < 0) {
		ostringstream s;
		s << "index = " << index << " must be >=0 or <size";
		throw illegalIndexValue(s.str());
	}
}
template<typename T>
chain<T>::chain(int initialCapacity) {
	size = 0;
	dummyHead = new chainNode<T>(NULL, nullptr);
}
template<typename T>
chain<T>::chain(const chain<T>& theList) {
	size = theList.size;
	chainNode<T>* sourceNode = theList.dummyHead;
	chainNode<T>* p = new chainNode<T>(sourceNode->element);
	dummyHead = p;
	sourceNode = sourceNode->next;
	while(sourceNode!=nullptr) {
		p->next = new chainNode<T>(sourceNode->element);
		p = p->next;
		sourceNode = sourceNode->next;
	}
}
template<typename T>
chain<T>::~chain() {
	while (dummyHead != nullptr) {
		chainNode<T>* deleteNode = dummyHead;
		dummyHead = dummyHead->next;
		delete deleteNode;
	}
}
template<typename T>
T& chain<T>::get(int index)const {
	checkIndex(index);
//Ҫ�ҵ���indexλ�õ�Ԫ�����Դ�dummyHead->next(������Ϊ0)��λ�ÿ�ʼ
	chainNode<T>* p = dummyHead->next;
	for (int i = 0; i < index; i++) {
		p = p->next;
	}//ִ��index��,p����index
	return p->element;
}
template<typename T>
T& chain<T>::getFirst()const {
	return get(0);
}
template<typename T>
T& chain<T>::getLast()const {
	return get(size-1);
}
template<typename T>
int chain<T>::find(const T& theElement)const {
	chainNode<T>* cur = dummyHead->next;
	for (int i = 0; i < size; i++) {
		if (cur->element == theElement)
			return i;
		else
			cur = cur->next;
	}
	return -1;
}
template<typename T>
void chain<T>::set(int index, const T& theElement) {
	checkIndex(index);
	chainNode<T>* p = dummyHead->next;
	for (int i = 0; i < index; i++)
		p = p->next;
	p->element = theElement;
}
template<typename T>
void chain<T>::insert(int index, const T& theElement) {
	if (index<0 || index>size)
		throw illegalIndexValue("index must be >=0 or <size");
	//��������������ҵ�����λ��ǰ���Ǹ��ڵ�
	//����ͷ��û��ǰһ��Ԫ�أ�������Ҫ����ʵ��
	//��������dummyHead֮���û����
//����Ҫ�ҵ���indexǰ���Ǹ�Ԫ�أ����Դӵ�һ��0������֮ǰ��dummyHead��ʼ
	chainNode<T>* p = dummyHead;
//��ǰָ��dummyHead,���ָ��index-1,��Ҫ�ƶ�index������
	for (int i = 0; i < index; i++) //�ص����ƶ��˶��ٴ�
//p��0֮ǰ��ʼִ��index�ε���index-1ǰ
		p = p->next;
	p->next = new chainNode<T>(theElement, p->next);
	size++;
}
template<typename T>
void chain<T>::erase(int index) {
	checkIndex(index);
	chainNode<T>* cur = dummyHead;
//��ǰָ��dummyHead,���ָ��index-1�������ƶ�index�Σ�����
	for (int i = 0; i < index; i++) {
		cur = cur->next;
	}
	chainNode<T>* deleteNode = cur->next;
	cur->next = deleteNode->next;
	delete deleteNode;
	size--;
}
template<typename T>
void chain<T>::output(ostream& out)const {
	for (chainNode<T>* cur = dummyHead->next; cur != nullptr; cur = cur->next) {
		out << cur->element<<" -> ";
	}
	out << "NULL";
}
template<typename T>
ostream& operator<<(ostream& out, const chain<T>& x) {
	x.output(out);
	return out;
}