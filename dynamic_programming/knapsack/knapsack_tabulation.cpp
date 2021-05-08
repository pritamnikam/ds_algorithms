#include <iostream>

using namespace std;

/*
0-1 Knapsack Problem solution using Tabulataion Method.
 TOP DOWN APPROACH

Example:
 Given weights and values of n items, put these items in a knapsack of capacity
 W to get the maximum total value in the knapsack. In  other words, given two 
 integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights 
 associated with n items  respectively. Also given an integer W which represents
 knapsack capacity, find out the maximum value subset of val[] such that sum  
 of the weights of this subset is smaller than or equal to W. You cannot break 
 an item, either pick the complete item, or don’t pick  it (0-1 property).

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/0-1-kna...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...
*/

namespace {
	const int kCapacity = 1000;
	const int kSize = 100;

	int dp[kSize][kCapacity];
}


int KnapsackWithTabulation(int wt[], int value[], int capacity, int size) {
	for (int i = 0; i <= size; ++i) {
		for (int j = 0; j <= capacity; ++j) {
			// base case:
			if (i == 0 || j == 0) {
				dp[i][j] = 0;
			}
		}

	}

	// for items with wt[i] and value[i]
	for (int i = 1; i <= size; ++i) {

		// for all capacities:
		for (int j = 1; j <= capacity; ++j) {

			// if item's weight is below present capacity:
			if (wt[i - 1] <= j) {
				// item chosen:
				int result_with = value[i - 1] + dp[i-1][j - wt[i - 1]];

				// item not chosen
				int result_without = dp[i - 1][j];

				// dp is max between these 2 choices
				dp[i][j] = std::max(result_with, result_without);
			}
			else {
				// otherwise: item is not chosen.
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	// Return result as dp last entry:
	return dp[size][capacity];
}

void testKnapsackWithTabulation() {
	int wt[] = { 1,3,4,5 };
	int val[] = { 1,4,5,7 };
	int capacity = 7;
	int size = 4;


	int result = KnapsackWithTabulation(wt, val, capacity, size);
	cout << result << endl;
}