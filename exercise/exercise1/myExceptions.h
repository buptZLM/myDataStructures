#pragma once
#include<iostream>
#include<string>
using namespace std;
class illegalParameterValue
{
public:
	illegalParameterValue(string message = "illegalParameterValue") {
		myString = message;
	}
	void output() { cout << myString; }
private:
	string myString;
};

class illegalIndex
{
public:
	illegalIndex(string message = "illegalIndex") {
		myString = message;
	}
	void output() { cout << myString; }
private:
	string myString;
};

