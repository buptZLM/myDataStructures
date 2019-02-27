#pragma once
#include"chainNode.h"
template<typename T>
chainNode<T>* removeElements2(chainNode<T>* head, int val) {
	chainNode<T>* dummyHead = new chainNode<T>(NULL, head);
	chainNode<T>* prev = dummyHead;
	while (prev->next!=nullptr)
	{
		if (prev->next->element == val) {
			chainNode<T>* deleteNode = prev->next;
			prev->next = prev->next->next;
			delete deleteNode;
		}
		else
		{
			prev = prev->next;
		}
	}
	return dummyHead->next;
	/*chainNode<T>* dummyHead = new chainNode<T>(-1, head);
	if (dummyHead->next == nullptr)
		return nullptr;
	chainNode<T>* prev = dummyHead;
	while (prev->next != nullptr) {
		if (prev->next->element == val) {
			chainNode<T>* deleteNode = prev->next;
			prev->next = prev->next->next;
			delete deleteNode;
		}
		else
		{
			prev = prev->next;
		}
	}
	return dummyHead->next;*/
}