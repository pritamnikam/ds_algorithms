#include <iostream>

#include <string>
#include <vector>

using namespace std;

/*

Print N-bit binary numbers having more 1’s than 0’s for any prefix

Patreon Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/39695797​

Problem Description: https://practice.geeksforgeeks.org/pr...​

Given a positive integer N, print all N bit binary numbers having more
1’s than 0’s for any prefix of the number.

Input:
2
2
3
Output:
11 10
111 110 101
*/


void PrintNBitBinaryNumbers(int n, int ones, int zeros, string output, vector<string>& vt) {
	if (n == 0) {
		vt.push_back(output);
		return;
	}

	if (ones > 0) {
		string op = output;
		op.push_back('1');

		PrintNBitBinaryNumbers(n - 1, ones + 1, zeros, op, vt);
	}

	if (ones > zeros) {
		string op = output;
		op.push_back('0');

		PrintNBitBinaryNumbers(n - 1, ones, zeros + 1, op, vt);
	}
}

void testPrintNBitBinaryNumbers() {
	int n = 3, ones = 0, zeros = 0;
	string output;
	vector<string> vt;

	PrintNBitBinaryNumbers(n, ones, zeros, output, vt);
}