#include <iostream>

using namespace std;

/*
Subset Sum Problem(Dynamic Programming)
Given a set of non-negative integers, and a value sum, determine if there is a 
subset of the given set with sum equal to given sum.

Example:

Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/subset-...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...​
*/

namespace {
	const int kMaxSum = 10000;
	const int kSize = 1000;

	bool dp[kSize][kMaxSum];
}

bool SubsetSum(int arr[], int sum, int size) {
	// Base case:
	for (int i = 0; i <= size; ++i) {
		dp[i][0] = true;
	}
		
	// Base case: 
	for (int j = 1; j <= sum; ++j) {
		dp[0][j] = false;
	}

	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= sum; ++j) {
			if (arr[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j - arr[i-1]] || dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[size][sum];
}

void testSubsetSum() {
	int arr[] = { 3, 34, 4, 12, 5, 2 };
	int size = 6;
	int sum = 9;

	bool result = SubsetSum(arr, sum, size);
	cout << result << endl;
}