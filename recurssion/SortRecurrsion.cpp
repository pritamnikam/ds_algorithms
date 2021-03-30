#include <iostream>

#include <vector>

using namespace std;
/*
Sort arr ascending order.
*/


void Insert(vector<int>& arr, int temp) {
	if (arr.size() == 0 || arr.back() < temp) {
		arr.push_back(temp);
		return;
	}

	int n = arr[arr.size() - 1];
	arr.pop_back();
	Insert(arr, temp);
	arr.push_back(n);
}

void Sort(vector<int>& arr) {
	if (arr.size() == 1) {
		return;
	}

	int n = arr[arr.size() - 1];
	arr.pop_back();
	Sort(arr);
	Insert(arr, n);
}


void testSortArr() {
	vector<int> vt = { 2,5,1,8 };
	Sort(vt);
}