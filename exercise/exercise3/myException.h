#pragma once
#include<iostream>
#include<string>
using namespace std;
class illegalParameterValue
{
private:
	string myString;
public:
	illegalParameterValue(string message="illegal Parameter Value") {
		myString = message;
	}
	void output() {
		cout << myString;
	}
};
using namespace std;
class illegalIndex
{
private:
	string myString;
public:
	illegalIndex(string message = "illegal Index") {
		myString = message;
	}
	void output() {
		cout << myString;
	}
};