#pragma once
#include<iostream>
#include<string>
using namespace std;
class illeaglParameterValue
{
private:
	string message;
public:
	illeaglParameterValue(string myMessage = " illeagl parameter value") {
		message = myMessage;
	}
	void output() {
		cout << message << endl;
	}
};

class illeaglIndexValue
{
private:
	string message;
public:
	illeaglIndexValue(string myMessage = " illeagl index value") {
		message = myMessage;
	}
	void output() {
		cout << message << endl;
	}
};

class stackError
{
private:
	string message;
public:
	stackError(string myMessage = " Stack Error") {
		message = myMessage;
	}
	void output() {
		cout << message << endl;
	}
};