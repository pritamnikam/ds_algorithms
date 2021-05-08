#include <iostream>

using namespace std;

/*
Coin Change Problem Maximum Number of ways
Given a value N, if we want to make change for N cents, and we have infinite
supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we
make the change? The order of coins doesn’t matter.

Example:
for N = 4 and S = {1,2,3}, 
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}.
So output should be 4.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/coin-ch...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

variation of subset sum and 
*/

namespace {
	const int kSum = 1000;
	const int kSize = 100;

	int dp[kSize][kSum];
}

int CoinChange(int coins[], int size, int sum) {
	for (int i = 0; i <= size; ++i)
		dp[i][0] = 1;

	for (int j = 1; j <= sum; ++j)
		dp[0][j] = 0;

	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= sum; ++j) {
			if (coins[i - 1] <= j) {
				dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[size][sum];
}

void testCoinChange() {
	int N = 4,
		S[] = { 1, 2, 3 },
		size = 3;

	int result = CoinChange(S, size, N);
	cout << result << endl;
}