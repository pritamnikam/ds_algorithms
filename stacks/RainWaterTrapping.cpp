#include <iostream>

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
	9 Rain Water Trapping

	Given n non-negative integers representing an elevation map where the width
	of each bar is 1, compute how much water it is able to trap after raining.
	Input: arr[]   = {2, 0, 2}
	Output: 2
	Structure is like below
	| |
	|_|
	We can trap 2 units of water in the middle gap.

	Input: arr[]   = {3, 0, 0, 2, 0, 4}
	Output: 10
	Structure is like below
		 |
	|    |
	|  | |
	|__|_|
	We can trap "3*2 units" of water between 3 an 2,
	"1 unit" on top of bar 2 and "3 units" between 2
	and 4.  See below diagram also.
	*/

vector<int> absoluteGreaterLeft(int arr[], int n) {
	vector<int> vt;
	for (int i = 0; i < n; ++i)
		vt.push_back(arr[i]);


	for (int i = 1; i < n; ++i)
		vt[i] = max(vt[i - 1], vt[i]);

	return vt;
}

vector<int> absoluteGreaterRight(int arr[], int n) {
	vector<int> vt;
	for (int i = 0; i < n; ++i)
		vt.push_back(arr[i]);

	for (int i = n - 2; i >= 0; --i) {
		vt[i] = max(vt[i + 1], vt[i]);
	}

	return vt;
}

int RainWaterTrapping(int arr[], int n) {
	vector<int> left = absoluteGreaterLeft(arr, n);
	vector<int> right = absoluteGreaterRight(arr, n);
	vector<int> water;
	for (int i = 0; i < n; ++i) {
		water.push_back(min(left[i], right[i]) - arr[i]);
	}

	int result = 0;
	for (int x : water)
		result += x;

	return result;
}