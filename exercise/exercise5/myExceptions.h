#pragma once
#include<iostream>
#include <string>
using namespace std;
class illegalParameterValue
{
private:
	string message;
public:
	illegalParameterValue(string theMessage = "illegalParameterValue") {
		message = theMessage;
	}
	void outputMessage() { cout<<message << endl; }
};