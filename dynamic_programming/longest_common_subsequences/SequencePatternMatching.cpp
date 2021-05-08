#include <iostream>

#include <string>

using namespace std;


/*
Sequence Pattern Matching

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
}

bool SequencePatternMatching(const string& text, const string& pattern) {
	int result = LCS(pattern, text);
	return result == pattern.length();
}

void testSequencePatternMatching() {

}