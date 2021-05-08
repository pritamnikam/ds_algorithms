#include <iostream>
#include <string>

using namespace std;


/*

Minimum Number of Insertion and Deletion to convert String a to String b

Minimum number of deletions and insertions to transform one string into another
Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.
Example:
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
         Minimum Insertion = 0

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/minimum...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...
*/

namespace {

    struct Operation {
        int insert_;
        int delete_;
    };

    const int kRows = 100;
    const int kCols = 100;

    int dp[kRows][kCols];
}

Operation MinimumNumberOfInsertionAndDeletion(const string& str1, const string& str2) {
    Operation result;

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

	result.delete_ = n - dp[n][m];
	result.insert_ = m - dp[n][m];

	return result;
}

void testMinimumNumberOfInsertionAndDeletion() {
	string str1 = "geeksforgeeks", str2 = "geeks";
	Operation op = MinimumNumberOfInsertionAndDeletion(str1, str2);
	cout << "Deletion: " << op.delete_ << ", Insertion: " << op.insert_ << endl;
}