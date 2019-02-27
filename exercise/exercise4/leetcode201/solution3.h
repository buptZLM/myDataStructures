#pragma once
#include"chainNode.h"
template<typename T>
chainNode<T>* removeElements3(chainNode<T>* head, int val) {
	if (head == nullptr)
		return nullptr;
	head->next = removeElements3(head->next, val);
	return head->element == val ? head->next : head;		
}
