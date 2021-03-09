/**
	* 6 Stock Span Problem
	*
	* The stock span problem is a financial problem where we have a series
	* of n daily price quotes for a stock and we need to calculate span of
	* stock’s price for all n days.
	*
	* The span Si of the stock’s price on a given day i is defined as the
	* maximum number of consecutive days just before the given day, for which
	* the price of the stock on the current day is less than or equal to its
	* price on the given day.
	*
	* For example, if an array of 7 days prices is given as
	* {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding
	* 7 days are {1, 1, 1, 2, 1, 4, 6}
	*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// pattern is similar to nearest-greater-to-left
vector<int> StockSpan(int arr[], int n) {
	vector<int> vt;
	stack<pair<int, int>> st;
	int psedoValue = 1;

	for (int i = 0; i < n; ++i) {
		if (st.empty()) {
			vt.push_back(psedoValue);
		}
		else if (st.top().second > arr[i]) {
			vt.push_back(st.top().first);
		}
		else {
			while (!st.empty() ||
				st.top().second <= arr[i]) {
				st.pop();
			}
			if (st.empty()) {
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
