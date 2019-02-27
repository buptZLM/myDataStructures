// exercise7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include"arrayList.h"
#include"arrayStack.h"
#include"leetcodeSolution.h"
#include"arrayQueue.h"
#include"loopQueue.h"
#include<cstdlib>
#include<ctime>

using namespace std;
template<typename T>
static double testQueue(queue<T> & q, int opCount) {
	clock_t starttime = clock();
	srand(time(0));
	for (int i = 0; i < opCount; i++) {
		int random = rand();
		q.enqueue(random);
	}
	for (int i = 0; i < opCount; i++)
		q.dequeue();
	clock_t endtime = clock();
	return(endtime - starttime) / 1000.0;
}
int main()
{
	arrayQueue<int> a;
	int opCount = 100000;
	double time1 = testQueue(a, opCount);
	cout << "arrayQueue time: " << time1 << "s" << endl;
	loopQueue<int> b;
	double time2 = testQueue(b, opCount);
	cout << "loopQueue time: " << time2 << "s" << endl;
	///*
	//arrayList<int> y(10);
	//cout << y;
	//for (int i = 0; i < 8; i++) {
	//	y.addLast(i);
	//}
	//y.addFirst(5);
	//y.addFirst(5);
	//y.addLast(10);
	//y.removeAll(5);
	//cout<<y;*/
	//
	//arrayStack<int> y(20);
	//int x = y.getSize();
	//bool l = y.empty();
	//cout << x << ",  " << boolalpha << l << endl;
	//for (int i = 0; i < 13; i++) {
	//	y.push(i);cout << y;
	//}
	//
	//y.pop();
	//cout << y;
	//cout << y.top();
	//
	/*Solution x;
	string s = "]}";
	cout << boolalpha << x.isValid(s);
	cin.get();
	return 0;*/
	/*loopQueue<int> y(1);
	for (int i = 0; i < 10; i++) {
	y.enqueue(i);cout << y;
	}


	for (int i = 0; i < 10; i++) {
	y.dequeue(); cout << y;
	}*/

	return 0;

}

