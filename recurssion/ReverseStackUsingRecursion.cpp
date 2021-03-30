#include <iostream>

#include <stack>
#include <vector>

using namespace std;

/*
Reverse a Stack in O(1) space using Recursion.

The Notes that I taught in the video and the Working Code (if any)
will be available on my Patreon page under the "Notes, Code And Support" tier.

Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes: https://www.patreon.com/posts/reverse...
*/
namespace {

	void InsertStack(stack<int>& st, int temp) {
		if (st.empty()) {
			st.push(temp);
			return;
		}

		int n = st.top();
		st.pop();

		InsertStack(st, temp);
		st.push(n);
	}

	void ReverseStack(stack<int>& st) {
		if (st.size() == 1) {
			return;
		}

		int n = st.top();
		st.pop();
		ReverseStack(st);

		InsertStack(st, n);
	}


}
