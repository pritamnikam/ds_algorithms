#include <iostream>

using namespace std;

/*

Count of subsets sum with a Given sum
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.
Example:

Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/count-o...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/
namespace {
	const int kMaxSum = 10000;
	const int kSize = 1000;

	int dp[kSize][kMaxSum];
}

int CountSubsetSum(int arr[], int size, int sum) {
	for (int i = 0; i <= size; ++i) {
		dp[i][0] = 1;
	}

	for (int j = 1; j <= sum; ++j) {
		dp[0][j] = 0; 
	}

	for (int i = 1; i <= size; ++i) {
		for (int j = 1; j <= sum; ++j) {
			if (arr[i - 1] <= j) {
				dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[size][sum];
}

void testCountSubsetSum() {
	int arr[] = { 1, 2, 3, 3 }, size = 4, sum = 6;
	int result = CountSubsetSum(arr, size, sum);
	cout << result << endl;
}