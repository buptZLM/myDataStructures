#pragma once
#include<iostream>
class testt
{
private:
	int a;
	int b;
public:
	testt() {
		a = 1;
		b = 2;
	}
	friend void fr(testt bb);
};
void fr(testt bb) {
	std::cout << bb.a << "  " << bb.b;
}