#include <iostream>

using namespace std;


/*

Minimum Subset Sum Difference

Sum of subset differences
Given a set of integers, the task is to divide it into two sets S1 and S2 such that
the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements,
Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2))
should be minimum.

Example:
Input:  arr[] = {1, 6, 11, 5}
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/partiti...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...
*/

namespace {

	const int kSize = 100;
	const int kSum = 10000;
	bool dp[kSize][kSum];

	int Sum(int arr[], int size) {
		int sum = 0;
		for (int i = 0; i < size; ++i) {
			sum += arr[i];
		}

		return sum;
	}

	bool SubsetSum(int arr[], int size, int sum) {
		for (int i = 0; i <= size; ++i) {
			dp[i][0] = true;
		}

		for (int j = 1; j <= sum; ++j) {
			dp[0][j] = false;
		}

		for (int i = 1; i <= size; ++i) {
			for (int j = 1; j <= sum; ++j) {
				if (arr[i - 1] <= j)
					dp[i][j] = dp[i - 1][j - arr[i-1]] || dp[i - 1][j];
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		return dp[size][sum];
	}
}


int MinimumSubsetSumDifference(int arr[], int size) {
	int sum = Sum(arr, size);

	SubsetSum(arr, size, sum);

	int result = INT_MAX;
	for (int i = 0; i <= sum/2; ++i) {
		if (dp[size][i])
			result = min(result, (sum - 2 * i));
	}

	return result;
}

void testMinimumSubsetSumDifference() {
	int arr[] = { 1, 6, 11, 5 };
	int size = 4;

	int result = MinimumSubsetSumDifference(arr, size);
	cout << result << endl;
}