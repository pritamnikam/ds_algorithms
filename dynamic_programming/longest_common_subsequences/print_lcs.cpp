#include <iostream>
#include <string>

using namespace std;

/*

Printing Longest Common Subsequence
Given two sequences, print the longest subsequence present in both of them.
Example:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/printin...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/

namespace {
	const int kRows = 100;
	const int kCols = 100;

	int dp[kRows][kCols];


int LCS(const string& str1, const string& str2, int length1, int length2) {
	for (int i = 1; i <= length1; ++i) {
		for (int j = 1; j <= length2; ++j) {
			if (str1[length1 - 1] == str2[length2 - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[length1][length2];
}

}

string PrintLCS(const string& str1, const string& str2, int n, int m) {
	LCS(str1, str2, n, m);

	int i = n, j = m;
	string result;
	while (n > 0 && m > 0) {
		if (str1[i-1] == str2[j-1]) {
			result.push_back(str1[i]);
			--i;
			--j;
		}
		else {
			if (dp[i][j - 1] > dp[i - 1][j])
				--j;
			else
				--i;
		}
	}

	std::reverse(result.begin(), result.end());
	return result;
}

void testPrintLCS() {
	for (int i = 0; i <= kRows; ++i) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	string str1 = "ABCDGH", str2 = "AEDFHR";
	string result = PrintLCS(str1, str2, str1.size(), str2.size());
	cout << result << endl;
}