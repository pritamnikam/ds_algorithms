#include <iostream>

#include <string>

using namespace std;


/*
Print Subsets | Print PowerSets | Print all Subsequences

Print all subsets of a String.

Problem Description: https://practice.geeksforgeeks.org/pr...​

Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes: https://www.patreon.com/posts/38704785

*/

namespace {
	void Solve(string input, string output) {
		if (input.empty()) {
			cout << output << endl;
			return;
		}

		string outpu1 = output;
		string output2 = output;

		output2.push_back(input[0]);
		input.erase(input.begin() + 0);

		Solve(input, outpu1);
		Solve(input, output2);
	}
}

void testPrintSubsets() {
	string input = "abc";
	string output = "";

	Solve(input, output);
}