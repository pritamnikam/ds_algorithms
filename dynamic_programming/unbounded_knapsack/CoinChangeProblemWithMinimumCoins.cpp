#include <iostream>

using namespace std;

/*
Coin Change Problem Minimum Numbers of coins

Given a value V, if we want to make change for V cents, and we have 
infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what 
is the minimum number of coins to make the change?

Example:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/find-mi...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...
*/

namespace {

	const int kSize = 100;
	const int kSum = 1000;

	int dp[kSize][kSum];
}

int CoinChangeWithMinimumCoins(int coins[], int size, int sum) {
	for (int j = 0; j <= sum; ++j) {
		dp[0][j] = INT_MAX - 1;
		dp[1][j] = (j % coins[0] == 0) ? j / coins[0] : INT_MAX - 1;
	}

	for (int i = 1; i <= size; ++i)
		dp[i][0] = 0;

	for (int i = 2; i <= size; ++i) {
		for (int j = 1; j <= sum; ++j) {
			if (coins[i - 1] <= j) {
				dp[i][j] = min(dp[i - 1][j],
					           1 + dp[i][j - coins[i - 1]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[size][sum];
}

void testCoinChangeWithMinimumCoins() {
	int coins[] = { 25, 10, 5 }, V = 30, size = 3;
	int result = CoinChangeWithMinimumCoins(coins, size, V);
	cout << result << endl;
}