// Array.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Array.h"

int main()
{
	Array<int> y;
	cout << y;
	for (int i = 0; i < 10; i++)
		y.insert(i, i);
	cout << y;
	y.insert(3, 100);
	cout << y;
	
	y.insert(5, 5);
	cout << y;
	y.eraseAll(5);
	cout << y;
	y.erase(6);
	cout << y;
	y.erase(7);
	cout << y;
	cin.get();
    return 0;
}

