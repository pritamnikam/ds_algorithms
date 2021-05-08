#include <iostream>

#include <string>

using namespace std;

/*

Minimum number of insertions to make a string palindrome
Given a string, find the minimum number of characters to be inserted to form Palindrome string out of given string

Examples:
ab: Number of insertions required is 1. bab
aa: Number of insertions required is 0. aa

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/minimum...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...
*/

namespace {
	const int kSize = 1000;
	int dp[kSize][kSize];

	int LCS(const string& str1, const string& str2) {
		for (int i = 0; i <= str1.length(); ++i)
			dp[i][0] = 0;

		for (int j = 0; j <= str2.length(); ++j)
			dp[0][j] = 0;

		for (int i = 1; i <= str1.length(); ++i) {
			for (int j = 1; j <= str2.length(); ++j) {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}



		return dp[str1.length()][str2.length()];
	}

	string Reverse(const string& str) {
		string temp = str;
		reverse(temp.begin(), temp.end());
		return temp;
	}
}

int MinimumNumberOfInsertionsToMakeAStringPalindrome(const string& str) {
	int result = LCS(str, Reverse(str));
	return str.length() - result;
}

void testMinimumNumberOfInsertionsToMakeAStringPalindrome() {
	cout << MinimumNumberOfInsertionsToMakeAStringPalindrome("ab") << endl;
	cout << MinimumNumberOfInsertionsToMakeAStringPalindrome("aa") << endl;
}