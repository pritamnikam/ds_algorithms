/*
Top K Frequent Numbers

Given an array of n numbers.
Your task is to read numbers from the array and keep at-most K numbers at the to
(According to their decreasing frequency) every time a new number is read.

We basically need to print top k numbers sorted by frequency when input stream
has included k distinct elements, else need to print all distinct elements sorted
by frequency.

Example:
Input :  arr[] = {5, 2, 1, 3, 2}
k = 4
Output : 5 2 5 1 2 5 1 2 3 5 2 1 3 5

*/

#include <iostream>
#include <queue>
#include <unordered_map>


using namespace std;

typedef pair<int, int> pi;

struct MinHeap {
	int size_;
	priority_queue<pi, vector<pi>, greater<pi>> heap_;

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


vector<int> TopKFrequestNumbers(int arr[], int n, int k) {
	// calculate frequency
	unordered_map<int, int> map;
	for (int i = 0; i < n; ++i) {
		map[arr[i]]++;
	}

	// Min-heap - greatest, top
	MinHeap mh;
	mh.size_ = k;
	for (auto it = map.begin(); it != map.end(); ++it) {
		mh.Push(make_pair(it->second, it->first));
	}

	vector<int> result;
	while (!mh.Empty()) {
		result.push_back(mh.Top().second);
		mh.Pop();
	}

	return result;
}