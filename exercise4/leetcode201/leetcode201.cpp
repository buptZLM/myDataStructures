// leetcode201.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"chainNode.h"
#include"solution1.h"
#include"solution3.h"
#include"solution2.h"


int main()
{
	int arr[] = { 6,2,3,6,5,6 };
	chainNode<int>* head = new chainNode<int>(arr, 6);	
	chainNode<int>* cur = removeElements1(head, 6);
	while (cur != nullptr) {
		cout << cur->element << ", ";
		cur = cur->next;
	}
    return 0;
}

