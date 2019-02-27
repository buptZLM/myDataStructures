#pragma once
#include<iostream>
template<typename T>
class segmentTree
{
private:
	T * data;
	int dataSize;
	T * tree;
public:
	int leftChild(int index) {
		return 2 * index + 1;
	}
	int rightChild(int index) {
		return 2 * index + 2;
	}
	public int getSize() {
		return dataSize;
	}
	segmentTree(T arr[], int n) {
		data = new T[n];
		for (int i = 0; i < n; i++) {
			data[i] = arr[i];
		}
		dataSize = n;
		tree = new T[4 * n];
		buildSegmentTree(0, 0, n - 1);
	}
	void buildSegmentTree(int treeIndex, int l, int r) {
		if (l == r) {
			tree[treeIndex] = data[l];
			return;
		}
		int leftChildIndex = leftChild(treeIndex);
		int rightChildIndex = rightChild(treeIndex);
		int mid = l + (r - l) / 2;
		buildSegmentTree(leftChildIndex, l, mid);
		buildSegmentTree(rightChildIndex, mid, r);
		tree[treeIndex] = tree[leftChildIndex] + tree[rightChildIndex];
	}
};