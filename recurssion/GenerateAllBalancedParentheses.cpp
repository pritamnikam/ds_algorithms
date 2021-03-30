#include <iostream>

#include <vector>
#include <string>

using namespace std;

/*
Generate all Balanced Parentheses

Patreon Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/39477428​

Problem Description: https://www.interviewbit.com/problems...​

Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/



void GenerateAllBalancedParentheses(int open, int close, string output, vector<string>& vt) {
	if (open == 0 && close == 0) {
		vt.push_back(output);
		return;
	}

	if (open) {
		string op = output;
		op.push_back('(');

		GenerateAllBalancedParentheses(open - 1, close, op, vt);
	}
	
	if (open < close) {
		string op = output;
		op.push_back(')');

		GenerateAllBalancedParentheses(open, close - 1, op, vt);
	}
}

void testGenerateAllBalancedParentheses() {
	int n = 3;
	int open = n, close = n;
	string output;
	vector<string> vt;
	GenerateAllBalancedParentheses(open, close, output, vt);
}