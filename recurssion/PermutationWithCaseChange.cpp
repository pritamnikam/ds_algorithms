#include <iostream>

#include <string>
#include <vector>

using namespace std;

/*
Permutation with Case Change | Recursion

Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/38831476​

Problem Description [we have assumed only lower case string]: https://www.geeksforgeeks.org/permute...​

Print all permutations of a string keeping the sequence but changing cases.

Examples:

Input : ab
Output : AB Ab ab aB
*/

void PermutationWithCaseChange(string input, string output, vector<string>& vt) {
	if (input.empty()) {
		vt.push_back(output);
		return;
	}

	string output1 = output;
	string output2 = output;

	output1.push_back(std::tolower(input[0]));
	output2.push_back(std::toupper(input[0]));
	input.erase(input.begin() + 0);

	PermutationWithCaseChange(input, output1, vt);
	PermutationWithCaseChange(input, output2, vt);
}

void testPermutationWithCaseChange() {
	string input = "abc";
	string output = "";
	vector<string> vt;

	PermutationWithCaseChange(input, output, vt);
}