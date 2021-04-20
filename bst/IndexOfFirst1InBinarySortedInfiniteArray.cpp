#include <iostream>

using namespace std;

/*
Index of First 1 in a Binary Sorted Infinite Array

Given an infinite sorted array consisting 0s and 1s.

The problem is to find the index of first ‘1’ in that array.

As the array is infinite, therefore it is guaranteed that
number ‘1’ will be present in the array.

Example:

Input : arr[] = {0, 0, 1, 1, 1, 1}
Output : 2

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/find-in...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...

*/

int FindIndexOf1(int* arr) {
	int start = 0, end = 1;

	while (arr[end] != 1) {
		start = end;
		end = 2 * end;
	}

	int result = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == 1) {
			result = mid;
			end = mid - 1;
		}
		else if (arr[mid] == 0) {
			// right sub array
			start = mid + 1;
		}
		else {
			// left sub-array
			end = mid - 1;
		}
	}

	return result;
}

void testFindIndexOf1() {
	int arr[] = { 0, 0, 1, 1, 1, 1 };
	int result = FindIndexOf1(arr);

	cout << "Index of First 1 in a Binary Sorted Infinite Array is: " << result << endl;
}