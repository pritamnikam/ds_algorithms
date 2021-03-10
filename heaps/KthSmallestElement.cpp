#include<iostream>
#include<queue>

using namespace std;

struct PQ {
	int k; // size of heap
	priority_queue<int> heap;  // max-heap

	void Push(int a) {
		heap.push(a);
		if (heap.size() > k) {
			Pop();
		}
	}

	void Pop() {
		heap.pop();
	}

	int Top() {
		return heap.top();
	}
};

int KthSmallestElement(int arr[], int n, int k) {
	PQ pq;
	pq.k = k;

	for (int i = 0; i < n; ++i) {
		pq.Push(arr[i]);
	}

	return pq.Top();
}