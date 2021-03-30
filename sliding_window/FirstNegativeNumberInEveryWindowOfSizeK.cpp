#include <iostream>


#include <vector>
#include <queue>

using namespace std;

/*
First Negative Number in every Window of Size K | Sliding Window

Given an array and a positive integer k, find the first negative integer for
each and every window(contiguous subarray) of size k.

Example:

Input:
2
5
-8 2 3 -6 10
2
8
12 -1 -7 8 -15 30 16 28
3

Output:
-8 0 -6 -6
-1 -1 -7 -15 -15 0
*/

vector<int> FirstNegativeNumberInEveryWindowOfSizeK(int arr[], int n, int k) {
	queue<int> negatives;
	vector<int> output;
	int i = 0;
	int j = 0;
	while (j < n) {
		if (arr[j] < 0)
			negatives.push(arr[j]);

		if (j - i + 1 < k) {
			++j;
		}
		else {
			if (negatives.empty()) {
				output.push_back(0);
			}
			else {
				output.push_back(negatives.front());

				if (arr[i] == negatives.front()) {
					negatives.pop();
				}
			}

			++i;
			++j;

			
		}
	}

	return output;
}

void testFirstNegativeNumberInEveryWindowOfSizeK() {
	{
		int K = 2, N = 5;
		int arr[] = { -8, 2, 3, -6, 10 };
		vector<int> vt = FirstNegativeNumberInEveryWindowOfSizeK(arr, N, K);
	}


	{
		int K = 3, N = 8;
		int arr[] = { 12, - 1, - 7, 8, - 15, 30, 16, 28 };
		vector<int> vt = FirstNegativeNumberInEveryWindowOfSizeK(arr, N, K);
	}
}