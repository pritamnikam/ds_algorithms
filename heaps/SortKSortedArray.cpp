/*
* 
* Sort a K Sorted Array | Sort Nearly Sorted Array
* 
* Given an array of n elements, where each element is at most k away
from its target position, devise an algorithm that sorts in O(n log k)
time.

For example, let us consider k is 2, an element at index 7 in the sorted
array, can be at indexes 5, 6, 7, 8, 9 in the given array.

Example:
Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
k = 3
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}
* 
*/

#include <iostream>
#include <queue>

using namespace std;

struct MinHeap {
	int size;
	priority_queue<int, vector<int>, greater<int>> pq;

	void Push(int a) {
		pq.push(a);
	}
	void Pop() {
		pq.pop();
	}

	int Top() {
		return pq.top();
	}

	bool Empty() {
		return pq.empty();
	}
};

vector<int> SortNearlySortedArray(int arr[], int n, int k) {
	MinHeap mh;
	vector<int> out;
	for (int i = 0; i < k; ++i) {
		mh.Push(arr[i]);
	}

	for (int i = k; i < n; ++i) {
		mh.Push(arr[i]);
		out.push_back(mh.Top());
		mh.Pop();
	}

	while (!mh.Empty()) {
		out.push_back(mh.Top());
		mh.Pop();
	}

	return out;
}