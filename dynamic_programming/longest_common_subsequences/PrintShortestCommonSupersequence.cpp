#include <iostream>
#include <string>

using namespace std;


/*
Print shortest common Supersequence

Given two strings X and Y, print the shortest string that has both X and Y as subsequences. 
If multiple shortest supersequence exists, print any one of them.

Examples:

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB"
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest
supersequence of X and Y

PROBLEM STATEMENT LINK: https://www.geeksforgeeks.org/print-s...​

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

string PrintShortestSommonSupersequence(const string& str1, const string& str2) {
	LCS(str1, str2);

	int i = str1.length();
	int j = str2.length();
	string result;

	while (i > 0 && j > 0) {
		if (str1[i - 1] == str2[j - 1]) {
			result.push_back(str1[i-1]);
			--i; --j;
		}

		else {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				result.push_back(str1[i-1]);
				--i;
			}
			else {
				result.push_back(str2[j-1]);
				--j;
			}
		}
	}

	while (i > 0) {
		result.push_back(str1[i-1]);
		--i;
	}

	while (j > 0) {
		result.push_back(str2[j-1]);
		--j;
	}

	reverse(result.begin(), result.end());
	return result;
}

void testPrintShortestSommonSupersequence() {
	{
		string X = "AGGTAB", Y = "GXTXAYB";
		string result = PrintShortestSommonSupersequence(X, Y);

		// Output: "AGXGTXAYB" OR "AGGXTXAYB"
		cout << result << endl;

	}
	{
		string X = "HELLO", Y = "GEEK";
		string result = PrintShortestSommonSupersequence(X, Y);

		// Output: "GEHEKLLO" OR "GHEEKLLO"
		cout << result << endl;
	}
	
}