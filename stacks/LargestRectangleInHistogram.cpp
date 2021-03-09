/***
	Find the largest rectangular area possible in a given histogram
	where the largest rectangle can be made of a number of contiguous bars.
	For simplicity, assume that all bars have same width and the width is 1 unit.

	NSL | index
	NSR | index
	width := right - left -1
	area := width * height
	maxArea = max(area)
	*/

#include <iostream>

#include <stack>
#include <vector>

using namespace std;

vector<int> LeftVector(int arr[], int n) {
	stack < pair<int, int>> st;
	vector<int> vt;
	int psedoValue = -1;

	for (int i = 0; i < n; ++i) {
		if (st.empty()) {
			vt.push_back(psedoValue);
		}
		else if (st.top().second < arr[i]) {
			vt.push_back(st.top().first);
		}
		else {
			while (!st.empty() || st.top().second >= arr[i]) {
				st.pop();
			}if (st.empty()) {
				vt.push_back(psedoValue);
			}
			else if (st.top().second > arr[i]) {
				vt.push_back(st.top().first);
			}
		}

		st.push(make_pair(i, arr[i]));
	}

	return vt;
}

vector<int> RightVector(int arr[], int n) {
	stack<pair<int, int>> st;
	vector<int> vt;
	int psedoValue = n;

	for (int i = n - 1; i >= 0; --i) {
		if (st.empty()) {
			vt.push_back(psedoValue);
		}
		else if (st.top().second < arr[i]) {
			vt.push_back(st.top().first);
		}
		else {
			while (!st.empty() || st.top().second >= arr[i]) {
				st.pop();
			}if (st.empty()) {
				vt.push_back(psedoValue);
			}
			else if (st.top().second > arr[i]) {
				vt.push_back(st.top().first);
			}
		}

		st.push(make_pair(i, arr[i]));
	}

	reverse(vt.begin(), vt.end());
	return vt;
}


int LargestRectangleInHistogram(int arr[], int n) {
	vector<int> left = LeftVector(arr, n);
	vector<int> right = RightVector(arr, n);
	vector<int> area;
	for (int i = 0; i < n; ++i) {
		int width = right[i] - left[i] - 1;
		area.push_back(width * arr[i]);
	}

	int maxArea = 0;
	for (int x : area) {
		if (maxArea < x) {
			maxArea = x;
		}
	}

	return maxArea;
}