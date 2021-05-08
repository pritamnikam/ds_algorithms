#include <iostream>
#include <string>

using namespace std;

/*
Longest Palindromic Subsequence
Given a sequence, find the length of the longest palindromic subsequence in it.
Example :
Input:"bbbab"
Output:4

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/longest...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/


namespace {
	const int kRows = 100;
	const int kCols = 100;

	int dp[kRows][kCols];
}

int LongestPalindromicSubsequence(const string& str) {
	int n = str.length();
	string str1 = str;
	std::reverse(str1.begin(), str1.end());
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 0;

	for (int j = 0; j <= n; ++j)
		dp[0][j] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (str[i - 1] == str1[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	return dp[n][n];
}

void testLongestPalindromicSubsequence() {
	string str = "bbbab";
	int result = LongestPalindromicSubsequence(str);
	cout << result << endl;
}