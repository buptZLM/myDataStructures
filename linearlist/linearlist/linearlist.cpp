// linearlist.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include"arraylist.h"
using namespace std;

int main()
{
	int a = 20;
	arraylist<int> arr(a);
	cout <<"is empty  "<<arr.empty()<<"   size="<<arr.size();
	int b = 33;
	arr.insert(0, b);
	cin.get();
    return 0;
}

