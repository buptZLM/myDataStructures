// DSexercise.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"array.h"
using namespace std;

int main()
{
	Array y(20);
	for (int i = 0; i < 10; i++) {
		y.addLast(i);
	}
	y.add(1, 100);
	y.addFirst(-1);
	cout << y << endl;
	y.remove(2);
	cout << y << endl;
	y.removeElement(4);
	cout << y << endl;
	cin.get();
    return 0;
}

