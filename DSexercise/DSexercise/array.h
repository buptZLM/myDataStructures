#pragma once
#include<iostream>
#include<sstream>
#include<iterator>
#include"myExceptions.h"
using namespace std;
class Array
{
private:
	int *data;
	int size;
	int capacity;
public:
	Array(int Capacity = 10);
	int getSize()const { return size; }
	int getCapacity()const { return sizeof(data)/sizeof(data[0]);}
	bool isEmpty()const { return size == 0; }
	void addLast(int e);
	void addFirst(int e);
	void add(int index, int e);
	void output(ostream& out)const;
	int get(int theIndex)const;
	void set(int index, int e);
	bool contains(int e)const;
	int find(int e)const;
	int remove(int index);
	void removeElement(int e);

};
Array::Array(int Capacity) {
	capacity = Capacity;
	data = new int[Capacity];
	size = 0;
}
void Array::addLast(int e){
	add(size, e);
}
void Array::addFirst(int e) {
	add(0, e);
}
void Array::add(int index, int e) {
	if (size == capacity)
		throw illeaglParameterValue("add failed. Array is full");
	if(index<0||index>size)
		throw illeaglParameterValue("add failed. index must be >=0 or <=size");
	for (int i = size - 1; i >= index; i--) 
		data[i + 1] = data[i];
	data[index] = e;
	size++;
} 
void Array::output(ostream& out)const {
	cout << "Array: size = " << size << ", capacity = " << capacity << endl;
	copy(data, data + size, ostream_iterator<int>(cout, " "));
}
ostream& operator<<(ostream& out, const Array & x) {
	x.output(out);
	return out;
}

int Array::get(int theIndex)const {
	if (theIndex < 0 || theIndex >= size)
		throw illeaglParameterValue("get failed, index must be >=0 or <size");
	return data[theIndex];
}
void Array::set(int index, int e) {
	data[index] = e;
}
bool Array::contains(int e)const {
	for (int i = 0; i < size; i++) {
		if (data[i] == e)
			return true;
		else
			return false;
	}
}
int Array::find(int e)const {
	for (int i = 0; i < size; i++) {
		if (data[i] == e)
			return i;
		else
			return -1;
	}
}
int Array::remove(int index) {
	if (index < 0 || index >= size)
		throw illeaglParameterValue
		("get failed, index must be >=0 or <size");
	int ret = data[index];
	for (int i = index+1; i < size; i++) {
		data[i-1] = data[i];
	}
	size--;
	return ret;
}
void Array::removeElement(int e) {
	int index = find(e);
	if (index != -1)
		remove(index);
}