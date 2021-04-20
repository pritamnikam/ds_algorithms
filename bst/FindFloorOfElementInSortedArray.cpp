#include <iostream>

using namespace std;

/*
Find Floor of an element in a Sorted Array

Given a sorted array and a value x, the floor of x is the largest element in array smaller
than or equal to x. Write efficient functions to find floor of x.

Example:

Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
Output : 2
2 is the largest element in arr[] smaller than 5.

PROBLEM STATEMENT LINK:https:https://www.geeksforgeeks.org/floor-i...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...

*/

int FindFloor(int arr[], int size, int n) {
	int start = 0;
	int end = size - 1;
	int result = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == n) {
			return mid;
		}

		if (arr[mid] < n) {
			// right sub-array
			result = arr[mid];
			start = mid + 1;
		}
		else {
			// left sub-array
			end = mid - 1;
		}
	}

	return result;
}

void testFindFloor() {
	int arr[] = { 1, 2, 8, 10, 10, 12, 19 };
	int x = 5;
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = FindFloor(arr, size, x);
	cout << "Floor of " << x << " is: " << result << endl;
}