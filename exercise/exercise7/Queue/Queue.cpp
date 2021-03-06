// Queue.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"chainQueue.h"
#include"arrayQueue.h"
#include"loopQueue.h"
#include<cstdlib>
#include<ctime>
template<typename T>
static double testQueue(queue<T>& q, int onCount) {
	clock_t startTime = clock();
	for (int i = 0; i < onCount; i++) {
		srand(time(0));
		int random = rand();
		q.enqueue(random);
	}
	for (int i = 0; i < onCount; i++) {
		q.dequeue();
	}
	clock_t endTime=clock();
	return (endTime - startTime) / 1000.0;
}

int main()
{
	chainQueue<int> x;

	/*for (int i = 0; i < 10; i++) {
		x.enqueue(i);
		cout << x << endl;
		if (i % 3 == 0) {
			x.dequeue();
			cout << x << endl;
		}	
	}*/
	
	arrayQueue<int> y;
	loopQueue<int> z;

	int onCount = 100000;

	double time1 = testQueue(x, onCount);
	double time2 = testQueue(y, onCount);
	double time3 = testQueue(z, onCount);
	cout << time1 << endl;
	cout << time2 << endl;
	cout << time3 << endl;
    return 0;
}

