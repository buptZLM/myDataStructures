// exercise2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"chain.h"

int main()
{
	chain<int> y;
	y.insert(0, 3);
	y.insert(0, 1);
	y.insert(1, 2);
	y.insert(3, 4);
	cout << y;
	cin.get();
	cin.get();
    return 0;
}

