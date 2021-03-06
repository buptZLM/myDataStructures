// binsort1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	void binsort(chain<studentRecord>& thechain, int range) {
		chain<studentRecord>* bin = new cahin<studentRecord>[range + 1];
		int studentNumber = thechain.size();
		for (int i = 1; i <= studentNumber; i++) {
			studentRecord x = thechain.get(0);
			thechain.erase(0);
			bin[x.score].insert(0, x);
		}
		for (int i = range; i >= 0; i--) {
			while (!bin[i].empty()) {
				studentRecord x = bin[i].get(0);
				bin[i].erase(0);
				thechain.insert(0, x);
			}
		}
		delete[]bin;
	}
    return 0;
}

