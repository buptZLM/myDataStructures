#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct chainNode
{
	chainNode<T>* next;
	T element;
	chainNode(){}
	chainNode(const T& element) {
		this->element = element;
	}
	chainNode(const T& element, chainNode<T>* next) {
		this->element = element;
		this->next=next;
	}
};