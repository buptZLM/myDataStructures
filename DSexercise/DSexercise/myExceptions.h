#pragma once
#include<iostream>
#include<string>
using namespace std;
class illeaglParameterValue
{
private:
	string myMessage;
public:
	illeaglParameterValue(string Message="illegalParameterValue") {
		myMessage = Message;
	}
	void output() {
		cout << myMessage << endl;
	}
};