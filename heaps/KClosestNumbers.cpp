/*
K Closest Numbers

Given an unsorted array and two numbers x and k, find k closest values to x.
Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3
*/

#include <iostream>
#include <queue>
#include <vector>

#include <algorithm>


using namespace std;

typedef pair<int, int> pi;

struct MaxHeap {
	int size_;
	priority_queue<pi> heap_;

	void Push(pi a) {
		heap_.push(a);
		if (heap_.size() > size_) {
			Pop();
		}
	}

	void Pop() {
		heap_.pop();
	}

	pi Top() {
		return heap_.top();
	}

	bool Empty() {
		return heap_.empty();
	}
};

vector<int> KClosetNumbers(int arr[], int n, int k) {
	MaxHeap hp;
	hp.size_ = k;

	for (int i = 0; i < n; ++i) {
		hp.Push(make_pair(abs(arr[i] - k), arr[i]));
	}

	vector<int> result;
	while (!hp.Empty()) {
		result.push_back(hp.Top().first);
	}

	return result;
}

