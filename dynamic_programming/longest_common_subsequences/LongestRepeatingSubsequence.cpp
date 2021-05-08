#include <iostream>

#include <string>

using namespace std;

/*
Longest Repeating Subsequence

Given a string, print the longest repeating subsequence such that the two subsequence
don’t have same string character at same position, i.e., any i’th character in the two
subsequences shouldn’t have the same index in the original string.

Example:
Input: str = "aab"
Output: "a"

The two subsequence are 'a'(first) and 'a'
(second). Note that 'b' cannot be considered
as part of subsequence as it would be at same
index in both.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/longest...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/

namespace {
	const int kSize = 1000;
	int dp[kSize][kSize];

	void LRS(const string& str1, const string& str2) {
		for (int i = 0; i <= str1.length(); ++i)
			dp[i][0] = 0;

		for (int j = 0; j <= str2.length(); ++j)
			dp[0][j] = 0;

		for (int i = 1; i <= str1.length(); ++i) {
			for (int j = 1; j <= str2.length(); ++j) {
				if (str1[i - 1] == str2[j - 1] && i != j) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}
}

string LongestRepeatingSubsequence(const string& str) {
	string str1, str2;
	str1 = str2 = str;

	
	LRS(str1, str2);
	int i = str1.length();
	int j = str2.length();
	string result;
	while (i > 0 && j > 0) {
		if (str1[i - 1] == str2[j - 1] && i != j) {
			result.push_back(str1[i - 1]);
			--i; --j;
		}
		else  {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				// result.push_back(str1[i - 1]);
				--i;
			}
			else {
				// result.push_back(str2[j - 1]);
				--j;
			}
		}
	}

	reverse(result.begin(), result.end());
	return result;
}

void testLongestRepeatingSubsequence() {
	string str = "aab";
	string result = LongestRepeatingSubsequence(str);

	// Output: "a"
	cout << result << endl;
}