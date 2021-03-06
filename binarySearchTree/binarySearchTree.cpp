// binarySearchTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<valarray>
#include"BST1.h"
#include"BST.h"
using namespace std;

int main()
{
	BST1<int> y;	
//	srand(time(0));
	for (int num = 0; num < 10; num++) {
		int random = rand() % 10;
		y.add(random);
	}
	cout<<boolalpha<<y.contains(9)<<endl;	
	cout << "preOrder:" << endl;
	y.preOrder();
	cout << endl;
	cout << "preOrderNR1:" << endl;
	y.preOrderNR1();
	cout << endl << endl;
	//y.preOrderNR2();
	//cout << endl << endl;
	cout << "inOrder:" << endl;
	y.inOrder();
	cout << endl << endl;
	cout << "inOrderNR:" << endl;
	y.inOrderNR();
	cout << endl <<endl;
	cout << "postOrder:" << endl;
	y.postOrder();
	cout << endl;
	cout << "levelOrder:" << endl;
	y.levelOrder();
	//int size = y.getSize();
	//cout << "size = "<<size << endl;
	for (int i = 0; i < y.getSize(); i++) {
		cout<< y.removeMax()<<" ";

	}
    return 0;
}

