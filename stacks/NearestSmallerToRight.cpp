#include <iostream>

#include <stack>
#include <vector>

using namespace std;

vector<int> NearestLesserToTheRight(int arr[], int n) {
	stack<int> st;
	vector<int> vt;

	for (int i = n - 1; i >= 0; --i) {
		if (st.empty()) {
			vt.push_back(-1);
		}
		else if (st.top() < arr[i]) {
			vt.push_back(st.top());
		}
		else {
			while (!st.empty() || st.top() >= arr[i]) {
				st.pop();
			}
			if (st.empty()) {
				vt.push_back(-1);
			}
			else if (st.top() < arr[i]) {
				vt.push_back(st.top());
			}
		}

		st.push(arr[i]);
	}

	reverse(vt.begin(), vt.end());
	return vt;
}