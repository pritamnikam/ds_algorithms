#include <iostream>
#include <string>

using namespace std;

/*

Longest Common Substring

Longest Common Substring(Dynamic Programming)
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
Examples:

Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
The longest common substring is “Geeks” and is of length 5.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/longest...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/


namespace {
	const int kRows = 100;
	const int kCols = 100;

	int dp[kRows][kCols];
}

int LongestCommonSubstring(const string& str1, const string& str2, int length1, int length2) {
	int result = 0;
	for (int i = 1; i <= length1; ++i) {
		for (int j = 1; j <= length2; ++j) {
			if (str1[length1 - 1] == str2[length2 - 1]) {
				result = max(result, 1 + dp[i - 1][j - 1]);
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	return result;
}

void testLongestCommonSubstring() {
	for (int i = 0; i <= kRows; ++i) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	string X = "GeeksforGeeks", y = "GeeksQuiz";
	int result = LongestCommonSubstring(X, y, X.length(), y.length());

	cout << result << endl;
}