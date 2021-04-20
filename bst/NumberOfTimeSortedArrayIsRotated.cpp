#include <iostream>

using namespace std;

/*
Number of Times a Sorted array is Rotated

Find the Rotation Count in Rotated Sorted array
Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.

Examples:

Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3,
6, 12, 15, 18}. We get the given array after
rotating the initial array twice.

Input : arr[] = {7, 9, 11, 12, 5}
Output: 4

Input: arr[] = {7, 9, 11, 12, 15};
Output: 0

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/find-ro...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...
*/

int NumberOfTimesArrayIsRotated(int arr[], int size) {
	int start = 0;
	int end = size - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		int prev = (mid + size - 1) % size;
		int next = (mid + 1) % size;

		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
			return mid;

		if (arr[start] <= arr[mid]) {
			// left array is sorted
			start = mid + 1;
		}
		else {
			// right array is sorted
			end = mid - 1;
		}
	}

	return -1;
}

void testNumberOfTimesArrayIsRotated() {
	{
		int arr[] = { 6,7,8,9,1,2,3,4,5 };
		int size = 9;
		int result = NumberOfTimesArrayIsRotated(arr, size);

		cout << "Rotations: " << result << endl;
	}
	
	{
		int arr[] = { 3, 4, 5, 6,7,8,9,1,2 };
		int size = 9;
		int result = NumberOfTimesArrayIsRotated(arr, size);

		cout << "Rotations: " << result << endl;
	}
}