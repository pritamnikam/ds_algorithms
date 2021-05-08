#include <iostream>

using namespace std;

/*
Count the number of subset with a given difference

s1 = {} , s2 = {}

s1 - s2 = diff   -------(1)
s1 + s2 = sum    -------(2)

(1) + (2) => s1 - s2 + s1 + s2 = diff + sum  
          => 2 * s1 = sum + diff
		  =>  s1 = (sum + diff)/2

*/

namespace {

	int Sum(int arr[], int size) {
		int sum = 0;
		for (int i = 0; i < size; ++i) {
			sum += arr[i];
		}

		return sum;
	}

	const int kSize = 100;
	const int kSum = 1000;

	int dp[kSize][kSum];
}

int CountOfSubsetWithGivenSum(int arr[], int size, int sum) {
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

int CountNumberOfSubsetWithGivenDifference(int arr[], int size, int diff) {
	int arr_sum = Sum(arr, size);

	for (int i = 0; i <= size; ++i) {
		dp[i][0] = 1;
	}

	for (int j = 1; j <= arr_sum; ++j) {
		dp[0][j] = 0;
	}

	int sum = (arr_sum + diff) / 2;
	return CountOfSubsetWithGivenSum(arr, size, sum);
}

void testCountNumberOfSubsetWithGivenDifference() {
	int arr[] = { 1,1,2,3 };
	int size = 4;
	int diff = 1;

	int result = CountNumberOfSubsetWithGivenDifference(arr, size, diff);
	cout << result << endl;
}