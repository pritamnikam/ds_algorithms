#include <iostream>

#include <algorithm>

using namespace std;

/*
Rod Cutting Problem

 Given a rod of length n inches and an array of prices that contains prices of all
 pieces of size smaller than n. Determine the  maximum value obtainable by cutting
 up the rod and selling the pieces.

Example:
if length of the rod is 8 and the values of different pieces are given as following,
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/cutting...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/


namespace {
	const int kSize = 100;
	const int kN = 10000;

	int dp[kSize][kN];
}

int RodCut(int lengths[], int prices[], int size, int N) {
	for (int i = 0; i <= size; ++i) {
		dp[i][0] = 1;
	}

	for (int j = 1; j <= N; ++j) {
		dp[0][j] = 0;
	}

	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (lengths[i - 1] <= N) {
				dp[i][j] = std::max(dp[i - 1][j], // not considering
									prices[i - 1] + dp[i][j - lengths[i - 1]]); // considering
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[size][N];
}

void testRodCutting() {
	int lengths[] = { 1,   2 ,  3,   4,   5,   6,   7,   8 },
		prices[] = { 1,   5 ,  8 ,  9,  10,  17,  17 , 20 },
		N = 8,
		size = 8;

	int result = RodCut(lengths, prices, size, N);
	cout << result << endl;
}