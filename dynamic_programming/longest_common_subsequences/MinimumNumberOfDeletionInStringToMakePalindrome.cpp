#include <iostream>
#include <string>

using namespace std;

/*
Minimum number of deletions to make a string palindrome

Given a string of size ‘n’. The task is to remove or delete minimum number
of characters from the string so that the resultant string is palindrome.
Examples :

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/minimum...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/

namespace {
	const int kRows = 100;
	const int kCols = 100;

	int dp[kRows][kCols];

	int LCS(const string& str1, const string& str2) {
		int m = str1.length();
		int n = str2.length();
		for (int i = 0; i <= m; ++i)
			dp[i][0] = 0;

		for (int j = 0; j <= n; ++j)
			dp[0][j] = 0;

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}

		return dp[m][n];
	}

}

int MinimumDeletionToMakePalindrome(const string& str) {
	string rev = str;
	reverse(rev.begin(), rev.end());
	int len = LCS(str, rev);

	return str.length() - len;
}

void testMinimumDeletionToMakePalindrome() {

}