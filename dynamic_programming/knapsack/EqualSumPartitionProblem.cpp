#include <iostream>

using namespace std;


/*
Equal Sum Partition Problem
Partition problem is to determine whether a given set can be partitioned into two
subsets such that the sum of elements in both subsets is same.

Examples:

arr[] = {1, 5, 11, 5}
Output: true
The array can be partitioned as {1, 5, 5} and {11}

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/partiti...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/

namespace {
	const int kSum = 1000;
	const int kSize = 100;

	bool dp[kSize][kSum];


	int Sum(int arr[], int size) {
		int sum = 0;
		for (int i = 0; i < size; ++i)
			sum += arr[i];

		return sum;
	}
}




bool _SubsetSum(int arr[], int size, int sum) {

	// Base case 1: Sum '0'
	for (int i = 0; i <= size; ++i) {
		dp[i][0] = true;
	}

	// Base case 2: Empty array
	for (int j = 1; j <= sum; ++j) {
		dp[0][j] = false;
	}

	// for all items in array
	for (int i = 1; i <= size; ++i) {

		// for all sub-set sum
		for (int j = 1; j <= sum; ++j) {

			// if item less that current sum
			if (arr[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
			}
			else {
				// otherwise:
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[size][sum];
}

bool EqualSumPartition(int arr[], int size) {
	int sum = Sum(arr, size);
	if (sum % 2 == 1)
		return false;

	return _SubsetSum(arr, size, sum / 2);
}

void testEqualSumPartition() {
	int arr[] = { 1, 5, 11, 5 }, size = 4;
	bool result = EqualSumPartition(arr, size);
	cout << result << endl;
}