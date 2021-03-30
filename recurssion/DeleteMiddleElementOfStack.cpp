#include <iostream>

#include <stack>
#include <vector>

using namespace std;


void Solve(stack<int> st, int k) {
	if (k == 1) {
		st.pop();
		return;
	}

	int n = st.top();
	st.pop();
	Solve(st, k - 1);
	st.push(n);
}

void DeleteMiddleElementOfStack(stack<int>& st) {
	if (st.empty())
		return;

	Solve(st, st.size() / 2 + 1);
}

void testDeleteMiddleElementOfStack() {
	vector<int> vt = { 2,5,1,8 };
	stack<int> st;
	for (int x : vt) {
		st.push(x);
	}

	// Solve(st, st.size()/2 + 1);
	DeleteMiddleElementOfStack(st);
}