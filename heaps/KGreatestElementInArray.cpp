#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct MinMeap {
	int size_;
	priority_queue<int, vector<int>, greater<int>> heap;

	void Push(int a) {
		heap.push(a);
		if (heap.size() > size_) {
			Pop();
		}
	}

	void Pop() {
		heap.pop();
	}

	int Top() {
		return heap.top();
	}

	bool Empty() {
		return heap.empty();
	}
};

vector<int> KGreatestElements(int arr[], int n, int k) {
	MinMeap mh;
	mh.size_ = k;

	for (int i = 0; i < n; ++i)
		mh.Push(arr[i]);

	vector<int> vt;
	while (!mh.Empty()) {
		vt.push_back(mh.Top());
		mh.Pop();
	}

	return vt;
}
