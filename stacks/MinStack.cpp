/*
  10 Minimum Element in Stack with Extra space
  Design a Data Structure SpecialStack that supports all the stack
  operations like push(), pop(), isEmpty(), isFull() and an additional
  operation getMin() which should return minimum element from the SpecialStack.

  All these operations of SpecialStack must be O(1). To implement SpecialStack,
  you should only use standard Stack data structure and no other data structure
  like arrays, list, .. etc.
*/

#include <iostream>

#include <stack>

using namespace std;

struct MinStack {
	void Push(int a) {
		if (st.empty() || st.top() > a) {
			minSt.push(a);
		}

		st.push(a);
	}
	
	void Pop() {
		if (st.empty())
			return;

		if (st.top() == minSt.top()) {
			minSt.pop();
		}

		st.pop();
	}

	int Top() {
		return st.top();
	}

	int MinElement() {
		return minSt.top();
	}

	stack<int> st;
	stack<int> minSt;
};