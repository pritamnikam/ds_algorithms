#include <iostream>

using namespace std;

/*

Find maximum element in Bitonic Array

Problem statement:
Given a bitonic array find the maximum value of the array.

An array is said to be bitonic if it has an increasing sequence of integers
followed immediately by a decreasing sequence of integers.

Example:

Input:
1 4 8 3 2

Output:
8

PROBLEM STATEMENT LINK:https://www.includehelp.com/icp/maxim...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...
*/

int FindMaximumElementInBitonicArray(int arr[], int size) {
	int start = 0;
	int end = size - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
			return mid;
		}

		if (arr[mid] < arr[mid + 1]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return -1;
}

void testFindMaximumElementInBitonicArray() {

}