#include <iostream>
#include <string>

using namespace std;

/*
Shortest Common Supersequence
Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
Examples:

Input:   str1 = "geek",  str2 = "eke"
Output: "geeke"

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/shortes...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/


namespace {
	const int kRows = 100;
	const int kCols = 100;

	int dp[kRows][kCols];
}


int ShortestCommonSupersequence(const string& str1, const string& str2) {
	int n = str1.length();
	int m = str2.length();

	for (int i = 0; i <= n; ++i)
		dp[i][0] = 0;

	for (int j = 0; j <= m; ++j)
		dp[0][j] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	return m + n - dp[n][m];
}

void testShortestCommonSupersequence() {
	string str1 = "geek", str2 = "eke";
	int result = ShortestCommonSupersequence(str1, str2);
	cout << result << endl;
}