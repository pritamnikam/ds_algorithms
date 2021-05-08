#include <iostream>

using namespace std;

/*
0-1 Knapsack Problem solution using Memoization.
 Knapsack Memoization code requires only 3 changes in Knapsack Recursion code.

Example:
 Given weights and values of n items, put these items in a knapsack of capacity W
 to get the maximum total value in the knapsack. In other words, given two integer
 arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with
 n items respectively. Also given an integer W which represents knapsack capacity,
 find out the maximum value subset of val[] such that sum  of the weights of this subset
 is smaller than or equal to W. You cannot break an item, either pick the complete item,
 or don’t pick  it (0-1 property).

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/0-1-kna...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/
namespace {

	const int kMaxCapacity = 1000;
	const int kMaxSize = 100;

	int dp[kMaxSize + 1][kMaxCapacity + 1];
}


int KnapsackWithMemoization(int wt[], int value[], int capacity, int size) {
	if (capacity == 0 || size == 0) {
		return 0;
	}

	if (dp[size][capacity] != -1) {
		return dp[size][capacity];
	}

	int id = size - 1;
	if (wt[id] <= capacity) {
		int result_with = value[id] + KnapsackWithMemoization(wt, value, capacity - wt[id], size - 1);
		int result_without = KnapsackWithMemoization(wt, value, capacity, size - 1);
		dp[size][capacity] = max(result_with, result_without);
	}
	else {
		dp[size][capacity] = KnapsackWithMemoization(wt, value, capacity, size - 1);
	}

	return dp[size][capacity];
}


void testKnapsackWithMemoization() {
	int wt[] = { 1,3,4,5 };
	int val[] = { 1,4,5,7 };
	int capacity = 7;
	int size = 4;

	for (int i = 0; i <= size; ++i) {
		for (int j = 0; j <= capacity; ++j) {
			dp[i][j] = -1;
		}
	}

	int result = KnapsackWithMemoization(wt, val, capacity, size);
	cout << result << endl;
}