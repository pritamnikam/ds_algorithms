/*
11 Minimum Element in Stack in O(1) Space

Design a Data Structure SpecialStack that supports all the stack operations
like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
which should return minimum element from the SpecialStack.

All these operations of SpecialStack must be O(1). To implement SpecialStack,
you should only use standard Stack data structure and no other data structure
like arrays, list, .. etc.
*/

#include <iostream>
#include <stack>

using namespace std;

struct MinStack2 {
	void Push(int a) {
		if (st.empty()) {
			minElement = a;
			st.push(a);
		}
		else if (a >= minElement) {
			st.push(a);
		}
		else {
			minElement = a;
			st.push(2 * a - 1);
		}
	}

	void Pop() {
		if (st.empty()) {
			return;
		} else if (st.top() >= minElement) {
			st.pop();
		}
		else {
			minElement = 2 * minElement - st.top();
			st.pop();
		}
	}

	int Top() {
		if (st.empty()) {
			return -1;
		}
		else if (st.top() >= minElement) {
			return st.top();
		}
		else {
			return minElement;
		}
	}
	
	int MinElement() {
		return minElement;
	}


	stack<int> st;
	int minElement = -1;
};