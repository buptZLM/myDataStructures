#pragma once
#include<iostream>
#include<string>
using namespace std;
class illegalIndex
{
private:
	string myString;
public:
	illegalIndex(string messages = "illegal Index") {
		myString = messages;
	}
	void output() { myString; }
};
class illegalParamentValue
{
private:
	string myString;
public:
	illegalParamentValue(string messages = "illegal Parament Value") {
		myString = messages;
	}
	void output() { myString; }
};