#pragma once
#include<stack>
#include<queue>
#include"myExceptions.h"
#include"treeNode.h"
template<typename T>
class BST
{
private:
	treeNode<T>* root;
	int size;
	treeNode<T>* add(treeNode<T>*& node, T element);
	treeNode<T>* minimum(treeNode<T>* node)const;
	treeNode<T>* removeMin(treeNode<T>* node);
	treeNode<T>* maximum(treeNode<T>* node)const;
	treeNode<T>* removeMax(treeNode<T>* node);
	bool contain(treeNode<T>* node, T e)const;
	void remove(treeNode<T>* node, T element);
	void preOrder(treeNode<T>* node)const;
	void preOrderNR(treeNode<T>* node)const;
	void inOrder(treeNode<T>* node)const;
	void inOrderNR(treeNode<T>* node)const;
	void postOrder(treeNode<T>* node)const;
	void levelOrder(treeNode<T>* node)const;
public:
	BST() { siz = 0; root = nullptr; }
	bool empty()const { return size == 0; }
	int getSize()const { return size; }
	void add(T element) { add(root, element); }
	T minimun()const { return minimun(root)->element; }
	T removeMin() { T ret = minimum(root)->element; removeMin(root); return ret; }
	T maximun()const { return maximun(root)->element; }
	T removeMax() { T ret = maximum(root)->element; removeMax(root); return ret; }
	bool contain(T element)const { return contain(root, element); }
	void remove(T e) { remove(root, e); }
	void preOrder()const { preOrder(root); }
	void preOrderNR()const { preOrderNR(root); }
	void inOrder()const { inOrder(root); }
	void inOrderNR()const { inOrderNR(root); }
	void postOrder()const { postOrder(root); }
	void levelOrder()const { levelOrder(root); }
};
template<typename T>
treeNode<T>* BST<T>::add(treeNode<T>*& node, T element) {
	if (node == nullptr) {
		node = new treeNode<T>(element);
		return node;
	}
	else
	{
		if (element > node->element)
			node->right = add(node->right, element);
		else if (element < node->element)
			node->left = add(node->left, element);
		return node;
	}
	size++;
}
template<typename T>
treeNode* BST<T>::minimum(treeNode<T>* node)const {
	if (node == nullptr)
		throw illegalParameterValue("illegal index");
	else
	{
		if (node->left == nullptr)
			return node;
		else
			return minimum(node->left)
	}
}
template<typename T>
treeNode<T>* BST<T>::removeMin(treeNode<T>* node) {
	if (node == nullptr)
		throw illegalParameterValue("illegal index");
	else
	{
		if (node->left == nullptr) {
			treeNode<T>* rnode = node->right;
			delete node;
			size--;
			return rnode;
		}
		else
		{
			node->left = removeMin(node->left)
				return node;
		}
	}
}
template<typename T>
treeNode* BST<T>::maximum(treeNode<T>* node)const {
	if (node == nullptr)
		throw illegalParameterValue("illegal index");
	else
	{
		if (node->right == nullptr)
			return node;
		else
			return maximum(node->right);
	}
}
template<typename T>
treeNode<T>* BST<T>::removeMax(treeNode<T>* node) {
	if (node == nullptr)
		throw illegalParameterValue("illegal index");
	else
	{
		if (node->right == nullptr) {
			treeNode<T>* lnode = node->left;
			delete node;
			size--;
			return lnode;
		}
		else
		{
			node->right = removeMin(node->right)
				return node;
		}
	}
}
template<typename T>
bool BST<T>::contain(treeNode<T>* node,T element)const {
	if (node == nullptr)
		return false;
	else if (node->element == element)
		return true;
	else if (node->element > element)
		return contain(node->left,element);
	else if (node->element < element)
		return contain(node->right,element);
} 
template<typename T>
treeNode<T>* BST<T>::remove(treeNode<T>* node, T element)
{
	if (node == nullptr)
		reutrn nullptr;
	else
	{
		if (element > node->element)
			node->right = remove(node->right, element);
		else if (element < node->element)
			node->left = remove(node->left, element);
		else
		{
			if (node->left == nullptr) {
				treeNode<T>* rnode = node->right;
				delete node;
				return rnode;
			}
			else if (node->right == nullptr) {
				treeNode<T>* lnode = node->left;
				delete node;
				return lnode;
			}
			else
			{
				treeNode<T>* newNode = new treeNode<T>(minimum(node->right)->element);
				newNode->right = removeMin(node->right);
				newNode->left = node->left;
				delete node;
				return newNode;
			}
		}
		return node;
	}
}
template<typename T>
void BST<T>::preOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	else
	{
		cout << node;
		preOrder(node->left);
		preOrder(node->right);
	}
}
template<typename T>
void BST<T>::preOrderNR(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	treeNode<T>* p = node;
	stack<treeNode<T>*> Stack;
	while (p!=nullptr || !Stack.empty()){
		while (p!=nullptr){
			cout << p->element;
			Stack.push(p);
			p = p->left;
		}
		treeNode<T>* cur = Stack.top();
		p = cur->right;
		Stack.pop();
	}
}
template<typename T>
void BST<T>::inOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	else
	{
		preOrder(node->left);
		cout << node;
		preOrder(node->right);
	}
}
template<typename T>
void BST<T>::inOrderNR(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	treeNode<T>* p = node;
	stack<treeNode<T>*> Stack;
	while (p != nullptr || !Stack.empty()) {
		while (p != nullptr) {
			Stack.push(p);
			p = p->left;
		}
		treeNode<T>* cur = Stack.top();
		cout << cur->element;
		p = cur->right;
		Stack.pop();
	}
}
template<typename T>
void BST<T>::postOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	else
	{
		preOrder(node->left);
		preOrder(node->right);
		cout << node;
	}
}
template<typename T>
void BST<T>::levelOrder(treeNode<T>* node)const {
	if (node == nullptr)
		return;
	queue<treeNode<T>*> Queue;
	Queue.push(node);
	while (!Queue.empty()) {
		treeNode<T>* cur = Queue.front();
		cout << cur->element<<", ";
		Queue.pop();
		if(node->left!=nullptr)
			Queue.push(cur->left);
		if(node->right!=nullptr)
			Queue.push(cur->right);
	}
}