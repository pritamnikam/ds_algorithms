#include <iostream>
#include <string>

using namespace std;


/*
* 
* Longest common subsequence Memoization

Introduction to Longest Common Subsequence Problem(LCS)
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
  A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/longest...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/

namespace {
	const int kRows = 100;
	const int kCols = 100;

	int dp[kRows][kCols];
}

int LCSMemoize(const string& str1, const string& str2, int length1, int length2) {
	if (length1 || length2)
		return 0;

	if (dp[length1][length2]) {
		return dp[length1][length2];
	}

	if (str1[length1 - 1] == str2[length2 - 1])
		dp[length1][length2] = 1 + LCSMemoize(str1, str2, length1 - 1, length2 - 1);
	else
		dp[length1][length2] = max(LCSMemoize(str1, str2, length1 - 1, length2),
			LCSMemoize(str1, str2, length1, length2 - 1));

	return dp[length1][length2];
}

void testLCSMemoize() {
	for (int i = 0; i <= kRows; ++i) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
}