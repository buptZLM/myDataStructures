#pragma once
#include<iostream>

template<typename T>
struct chainNode
{
	T element;
	chainNode<T>* next;
	chainNode() {};
	chainNode(const T& theElement) {
		element = theElement;
	}
	chainNode(const T& element, chainNode<T>* next) {
		this->element = element;
		this->next = next;
	}
};