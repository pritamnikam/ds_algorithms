#include <iostream>

/*
[FREE] Beginners lessons in programming by
Codechef - https://unacademy.com/a/beginner-special-classes-programming


Patreon Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/44434748​

Playlist Link: https://www.youtube.com/playlist?list...​

Problem Description:

Given an array containing N positive integers and an integer K.
Your task is to find the length of the longest Sub-Array with sum of the elements
equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is:
4
*/

#include<vector>

using namespace std;

int LongestSubarrayOfSumK(int arr[], int n, int k) {
	int result = 0;

	int sum = 0;
	int i = 0;
	int j = 0;
	while (j < n) {
		// calculations:
		sum = sum + arr[j];

		// check the window reaching the sum.
		if (sum < k) {
			++j;
		}
		else {
			if (sum == k) {
				result = max(result, j - i + 1);
			}
			else if (sum > k) {
				// Remove i from calculations
				while (sum > k) {
					sum = sum - arr[i];

					// slide i
					++i;
				}

				// check before we proceed further:
				if (sum == k) {
					result = max(result, j - i + 1);
				}
			}

			// slide j
			++j;
		}
	}

	return result;
}

void testLongestSubarrayOfSumK() {
	int n = 7, k = 5;
		int arr[] = { 4, 1, 1, 1 ,2, 3, 5 };
		int result = LongestSubarrayOfSumK(arr, n, k);
		cout << result << endl;
}