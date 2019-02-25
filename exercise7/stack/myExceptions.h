#pragma once
#include<iostream>
#include<string>
using namespace std;

class illegalParameterValue
{
private:
	string message;
public:
	illegalParameterValue(string myMessage = "illegal parameter")
	{
		message = myMessage;
	}
	void output() {
		cout << message << endl;
	}
};

class illegalIndexValue
{
private:
	string message;
public:
	illegalIndexValue(string myMessage = "illegal index")
	{
		message = myMessage;
	}
	void output() {
		cout << message<<endl;
	}
};