// exercise_1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"Queue.h"
#include"stack.h"
#include"arrayStack.h"
#include"chainStack.h"
#include"chainQueue.h"
#include"chainNode.h"
#include"loopQueue.h"
#include"arrayQueue.h"
#include<ctime>
#include<cstdlib>
using namespace std;
template<typename T>
static double testStack(stack<T>& theStack, int onCount) {
	clock_t startTime = clock();
	for (int i = 0; i < onCount; i++) {
		srand(time(0));
		int random = rand();
		theStack.push(random);
	}
	for (int i = 0; i < onCount; i++) {
		theStack.pop();
	}
	clock_t endTime = clock();
	return (endTime - startTime) / 1000.0;
}
template<typename T>
static double testQueue(queue<T>& theStack, int onCount) {
	clock_t startTime = clock();
	for (int i = 0; i < onCount; i++) {
		srand(time(0));
		int random = rand();
		theStack.enqueue(random);
	}
	for (int i = 0; i < onCount; i++) {
		theStack.dequeue();
	}
	clock_t endTime = clock();
	return (endTime - startTime) / 1000.0;
}

//template<typename T>
static int findElement(chainNode<int>* Head, int E) {
	static int i = 0;
	if (Head == nullptr)
		return 1;
	if (Head->element == E) {
		return 0;
	}
	else {
		i = 1 + findElement(Head->next, E);
		return i;
	}
}
//template<typename T>
static void insertElement(int index, int E, chainNode<int>* prev) {
	static chainNode<int>* dummyHead = new chainNode<int>(NULL, prev);
	static chainNode<int>* p = dummyHead;
	if (index != 0){
		p = p->next;
		insertElement(index - 1, E, prev->next);
	}
	else
	{
		p->next = new chainNode<int>(E, p->next);
	}
}
static int erase(int index,chainNode<int>* prev) {
	static chainNode<int>* dummyhead = new chainNode<int>(NULL, prev);
	static chainNode<int>* p = dummyhead;
	static int x;
	if (index != 0) {
		p = p->next;
		erase(index - 1, prev->next);
	}
	else
	{
		chainNode<int>* deleteNode = p->next;
		x = deleteNode->element;
		p->next = deleteNode->next;
		delete deleteNode;
	}
	return x;
}


int main()
{
//	chainStack<int> x;
//	arrayStack<int> y;
//	int onCount = 10000;
//	double time1 = testStack(x, onCount);
//	double time2 = testStack(y, onCount);
//	cout <<"chainStack: "<< time1 <<"s"<< endl;
//	cout <<"arrayStack"<<time2 << "s" << endl;
//	chainQueue<int> z;
//	arrayQueue<int> w;
////	int onCount = 10000;
//	double time3 = testQueue(z, onCount);
//	double time4 = testQueue(w, onCount);
//	cout <<"chainQueue"<<time3 << "s" << endl;
//	cout <<"arrayQueue"<<time4 << "s" << endl;

	/*chainQueue<int> y;
	for (int i = 0; i < 15; i++) {
		y.enqueue(i);
		cout << y<<endl;
	}
	for (int i = 0; i < 15; i++) {
		y.dequeue();
		cout << y<<endl;
	}
*/
	/*loopQueue<int> y;
	for (int i = 0; i < 9; i++) {
		y.enqueue(i); cout << y;
	}
	for (int i = 0; i < 6; i++) {
		y.dequeue(); cout << y;
	}
	for (int i = 9; i < 14; i++) {
		y.enqueue(i); cout << y;
	}
	for (int i = 0; i < 10; i++) {
		y.dequeue(); cout << y;
	}*/
	int num[] = { 1,2,6,4,5,6,7 };
	chainNode<int>* head = new chainNode<int>(num, 7);
	chainList<int> y;
	chainNode<int>* p = head;
	int a = erase(3, head);
	int ss = findElement(head,5);//如果没找到4则返回数组长度
	//insertElement(3, 666, head);
	while (p!=nullptr)
	{
		cout << p->element;
		p = p->next;
	}
	cout << endl;
	cout <<a<<", "<< ss;
    return 0;
}

