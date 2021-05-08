#include <iostream>
#include <string>

using namespace std;

/*
Longest common subsequence Top down DP

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

int LCSTabulation(const string& str1, const string& str2, int length1, int length2) {
	for (int i = 1; i <= length1; ++i) {
		for (int j = 1; j <= length2; ++j) {
			if (str1[length1 - 1] == str2[length2 - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[length1][length2];
}

void testLCSTabulation() {
	for (int i = 0; i <= kRows; ++i) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}		
}