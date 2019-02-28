#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class illegalParameterValue
{
private:
	string message;
public:
	illegalParameterValue(string myMessage = "illegalParameterValue") {
		message = myMessage;
	}
	void output() {
		cout << message << endl;
	}
	
};