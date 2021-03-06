// stack.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"chainStack.h"
#include"arrayStack.h"
#include<cstdlib>
#include<ctime>
using namespace std;

template<typename T>
static double testQueue(stack<T>& q, int opCount) {
	clock_t startTime = clock();
	for (int i = 0; i<opCount; i++) {
		srand(time(0));
		int random = rand();
		q.push(random);
	}
	for (int i = 0; i < opCount; i++)
		q.pop();
	clock_t endTime = clock();
	return (endTime - startTime) / 1000.0;
}

int main()
{
	chainStack<int> y(20);
	arrayStack<int> z(20);
	int opCount = 1000000;
	double time1 = testQueue(y, opCount);
	double time2 = testQueue(z, opCount);
	cout << "chainStack : "<<time1<< endl;
	cout << "arrayStack : " << time2 << endl;
	//cout << "arrayStack" << testQueue(z, opCount) << endl;
	
    return 0;
}

