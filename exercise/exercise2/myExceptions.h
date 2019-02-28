#pragma once
#include<iostream>
#include<string>
using namespace std;
class illegalParameterValue
{
public:
	illegalParameterValue(string message = "illegal paramter value") {
		mystring = message;
	}
	void output() { cout << mystring; }
private:
	string mystring;
};
class illegalIndex
{
public:
	illegalIndex(string message = "illegal index") {
		mystring = message;
	}
	void output() { cout << mystring; }
private:
	string mystring;
};