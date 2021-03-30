#include <iostream>

#include <string>
#include <vector>

using namespace std;

/*
Letter Case Permutation | Recursion

Patreon Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/38832898​

Problem Description: https://leetcode.com/problems/letter-...​

Given a string S, we can transform every letter individually to be
lowercase or uppercase to create another string.  Return a list of all
possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]

*/

void LetterCasePermutation(string input, string output, vector<string>& vt) {
	if (input.empty()) {
		vt.push_back(output);
		return;
	}

	

	if (std::isdigit(input[0])) {
		string output1 = output;
		output1.push_back(input[0]);
		input.erase(input.begin() + 0);
		LetterCasePermutation(input, output1, vt);
		return;
	}

	string output1 = output;
	string output2 = output;
	output1.push_back(std::tolower(input[0]));
	output2.push_back(std::toupper(input[0]));
	input.erase(input.begin() + 0);

	LetterCasePermutation(input, output1, vt);
	LetterCasePermutation(input, output2, vt);
}

void testLetterCasePermutation() {
	string S = "a1b2";
	string O = "";

	vector<string> vt;
	LetterCasePermutation(S, O, vt);
}