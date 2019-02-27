#pragma once
#include<iostream>
#include<string>
using namespace std;
class illegalParameterValue {
private:
	string message;
public:
	illegalParameterValue(string myMessage = "illegal parameter value") {
		message = myMessage;
	}
	void output() { cout << message; }

};