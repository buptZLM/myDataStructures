// testt.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
void a(int & b)
int main() 
{
	a(4);
    return 0;
}
void a(const int &b)
{
	cout << b << endl;

}
