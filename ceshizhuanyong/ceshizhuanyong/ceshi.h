#pragma once
class A
{
private:
	int *p;
	const int b = 10;
public:
	A() 
	{
		p = new int[b];
		for (int i = 0; i < b; i++)
		{
			p[i] = i;
		}
	}
	~A() { delete[]p; }

	void get() { p[9].~A(); }
	
	
};