#include <iostream>


using namespace std;

/*
Maximum Sum Subarray of size K  | Sliding Window 

Given an array of integers Arr of size N and a number K.
Return the maximum sum of a subarray of size K.

Example:

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]

Output:
700

Explanation:
Arr3  + Arr4 =700,
which is maximum.

*/

long MaximumSumSubarrayOfSizeK(int arr[], int n, int k) {
	int start = 0;
	int end = 0;
	int sum = 0;
	int maxSum = 0;
	while (end < n) {
		sum = sum + arr[end];
		if (k > end - start + 1) {
			++end;
		}
		else {
			if (maxSum < sum) {
				maxSum = sum;
			}

			sum = sum - arr[start];
			++start;
			++end;
		}
	}

	return maxSum;
}

void testMaximumSumSubarrayOfSizeK() {
	int N = 4, K = 2;
	int	Arr[] = { 100, 200, 300, 400 };

	cout << MaximumSumSubarrayOfSizeK(Arr, N, K) << endl;
}