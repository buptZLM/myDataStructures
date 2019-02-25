#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct chainNode {
	chainNode<T>* next;
	T element;
	chainNode() {
		element = NULL;
		next = nullptr;
	}
	chainNode(T element) {
		this->element = element;
		next = nullptr;
	}
	chainNode(T element, chainNode<T>* next) {
		this->element = element;
		this->next = next;
	}
};