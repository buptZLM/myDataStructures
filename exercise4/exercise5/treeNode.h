 #pragma once
#include<iostream>
template<typename T>
struct treeNode
{
	treeNode<T>* left;
	treeNode<T>* right;
	T element;
	treeNode() {
		left = right = nullptr;
		element = NULL;
	}
	treeNode(T element) {
		this->element = element;
		left = right = nullptr;
	}
};