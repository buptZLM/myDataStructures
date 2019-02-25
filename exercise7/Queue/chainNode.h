#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct chainNode
{
	T element;
	chainNode<T>* next;
	chainNode(const T& element, chainNode<T>* next) {
		this->element = element;
		this->next = next;
	}
	chainNode(const T& element) {
		this->element = element;
		this->next = nullptr;
	}
};