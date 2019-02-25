#pragma once
#include"chainNode.h"
template<typename T>
chainNode<T>* removeElements1(chainNode<T>* head, int val) {
	while(head->element == val) {
		chainNode<T>* deleteNode = head;
		head = head->next;
		delete deleteNode;
	}
	if (head == nullptr)
		return nullptr;
	chainNode<T>* prev = head;
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
	return head;



	/*while (head != nullptr && head->element == val) {
		chainNode<T>* deleteNode = head;
		head = head->next;
		delete deleteNode;
	}
	if (head == nullptr)
		return nullptr;

	chainNode<T>* prev = head;
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
	return head;*/
}


