#include <iostream>

using namespace std;

/*

Ceil of an element in a Sorted Array

Given a sorted array and a value x, the ceiling of x is the smallest element in array
greater than or equal to x, and the floor is the greatest element smaller than or equal to x.

Assume than the array is sorted in non-decreasing order. Write efficient functions to find floor
and ceiling of x.

Examples :

For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    floor doesn't exist in array,  ceil  = 1
For x = 1:    floor  = 1,  ceil  = 1
For x = 5:    floor  = 2,  ceil  = 8
For x = 20:   floor  = 19,  ceil doesn't exist in array

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/ceiling...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...
*/

int FindCeil(int arr[], int size, int n) {
	int start = 0, end = size - 1, result = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == n)
			return arr[mid];
		if (arr[mid] < n) {
			// right sub-array
			start = mid + 1;
		}
		else {
			// left sub-array
			result = arr[mid];
			end = mid - 1;
		}
	}

	return result;
}

void testFindCeil() {
	int arr[] = { 1, 2, 8, 10, 10, 12, 19 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int x = 5;

	int result = FindCeil(arr, size, x);
	cout << "Ceil of " << x << " is: " << result << endl;
}