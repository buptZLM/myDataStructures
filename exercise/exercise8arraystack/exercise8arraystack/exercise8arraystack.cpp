// exercise8arraystack.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<string>
#include"letest.h"
#include<stack>
#include"arrayList.h"
using namespace std;
int main()
{
	Solution x;
	string s = "]}";
	cout<<boolalpha<<x.isValid(s);
	

	//arrayList<int> y(15);
	//for (int i = 0; i < 10; i++) {
	//	y.insert(i,i);
	//	cout << y << endl;
	//}
	//for (int i = 0; i < 8; i++) {
	//	y.removeLast();
	//	cout << y << endl;
	//}
	//arrayList<int> x = y;
	//cout << x;
	//cin.get();


	/*string str1 = "qwertyui";
	const char *str2 = "abcdefghi"; 
	char str3[] = "asdfghjkl";
	string s1(str1,2,10);
	string s2(str2,2,10);
	string s3(str3,2,10);
	string s4(3, 'c');
	cout << s1 << ", " << s2 << ", " << s3 << ", "<<s4<<size(str3);*/



	cin.get();
    return 0;
}
