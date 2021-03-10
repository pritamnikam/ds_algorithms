/*
K Closest Points To Origin

Given a list of points on the 2-D plane and an integer K.
The task is to find K closest points to the origin and print them.

Note: The distance between two points on a plane is the Euclidean distance.

Example:
Input : point = [[3, 3], [5, -1], [-2, 4]], K = 2
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> ppi;


// closet to origin
struct MaxHeap {
	int size;
	priority_queue<ppi> heap;

	void Push(ppi a) {
		heap.push(a);
		if (heap.size() > size) {
			heap.pop();
		}
	}

	void Pop() {
		heap.pop();
	}

	ppi Top() {
		return heap.top();
	}

	bool Empty() {
		return heap.empty();
	}
};

vector<pi> KClosestPointsToOrigin(int arr[][2], int n, int k) {
	MaxHeap mh;
	mh.size = k;
	for (int i = 0; i < n; ++i) {
		int key = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
		pair<int, int> value = make_pair(arr[i][0], arr[i][1]);
		mh.Push(make_pair(key, value));
	}

	vector<pi> out;
	while (!mh.Empty()) {
		out.push_back(mh.Top().second);
	}

	return out;
}