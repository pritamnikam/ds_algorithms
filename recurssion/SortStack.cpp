#include <iostream>

#include <stack>
#include <vector>

using namespace std;

void InsertStack(stack<int>& st, int temp) {
	if (st.empty() || st.top() < temp) {
		st.push(temp);
		return;
	}

	int n = st.top();
	st.pop();
	InsertStack(st, temp);
	st.push(n);
}

void SortStack(stack<int>& st) {
	// base case:
	if (st.empty())
		return;

	int temp = st.top();
	st.pop();
	SortStack(st);
	InsertStack(st, temp);
}

void testSortStack() {
	vector<int> vt = { 2,5,1,8 };
	stack<int> st;
	for (int x : vt) {
		st.push(x);
	}
	SortStack(st);
}