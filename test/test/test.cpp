// test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<memory>
#include<vector>
#include<iterator>
#include<string>
using namespace std;

int main()
{
	//cin.clear();
	//unique_ptr<double> pd(new double(3));
	int cats[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> a(cats,cats+10);
	//istream_iterator<int, char> in_iter(cin);
	//copy(in_iter,istream_iterator<int,char>(), a.begin());
	(&a)->~vector<int>();
	copy(a.begin(), a.end(), ostream_iterator<int, char>(cout, " "));

	//const char s[3]="lk";
	//cin.getline(s,3);
	//string d(s);
	//cout <<d<<endl;
	//getline(cin,p);
	//cout << p << endl;
	//cout << *pd;
    return 0;
}

