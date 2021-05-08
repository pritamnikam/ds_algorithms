#include <iostream>

using namespace std;


/*
Target Sum Problem

Given a list of non-negative integers, a1, a2, ..., an, and a target, S.
Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

PROBLEM STATEMENT LINK:https://leetcode.com/problems/target-...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...


------------------
Special case of 'Count the number of subset with a given difference'

s1 => set with all positive numers
s2 => set of all negative numbers
diff => target sum

s1 + s2 = sum(arr)     ----- [1]
s1 - s2 = target_sum   ----- [2]

[1] & [2] addition

s1 + s2 + s1 - s2 = sum(arr) + target_sum
s1 = (sum(arr) + target_sum) / 2;

*/

namespace {
	const int kSize = 100;
	const int kSum = 1000;

	int dp[kSize][kSum];

	int Sum(int arr[], int size) {
		int sum = 0;
		for (int i = 0; i < size; ++i) {
			sum += arr[i];
		}

		return sum;
	}

	int CountNumberOfSubsetSum(int arr[], int size, int sum) {
		for (int i = 1; i <= size; ++i) {
			for (int j = 1; j <= sum; ++j) {
				if (arr[i - 1] <= j) {
					dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		return dp[size][sum];
	}

	int TargetSum(int arr[], int size, int target_sum) {
		int arr_sum = Sum(arr, size);
		int sum = (arr_sum + target_sum) / 2;
		for (int i = 0; i <= size; ++i)
			dp[i][0] = 1;

		for (int j = 1; j <= arr_sum; ++j)
			dp[0][j] = 0;

		return CountNumberOfSubsetSum(arr, size, sum);
	}
}

void testTargetSum() {
	int arr[] = { 1, 1, 1, 1, 1 }, size = 5, S = 3;
	int result = TargetSum(arr, size, S);
	cout << result << endl;
}