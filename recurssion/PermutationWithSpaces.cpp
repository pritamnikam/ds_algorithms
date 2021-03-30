#include <iostream>

#include <string>
#include <vector>

using namespace std;

/*
Permutation with spaces

Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/38785851​

Problem Description: https://practice.geeksforgeeks.org/pr...​

Given a string you need to print all possible strings that can be made by
placing spaces (zero or one) in between them. Output should be printed in
sorted increasing order of strings.

Input:  str[] = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
*/

void PermutationWithSpaces(string input, string output, vector<string>& result) {
	if (input.empty()) {
		result.push_back(output);
		return;
	}

	string output1 = output;
	string output2 = output;

	output1.push_back(input[0]);
	output2.push_back(' ');
	output2.push_back(input[0]);

	input.erase(input.begin() + 0);

	PermutationWithSpaces(input, output1, result);
	PermutationWithSpaces(input, output2, result);
}

void testPermutationWithSpaces() {
	string input = "abc";
	string output = "";
	vector<string> vt;

	output.push_back(input[0]);
	input.erase(input.begin() + 0);

	PermutationWithSpaces(input, output, vt);
}