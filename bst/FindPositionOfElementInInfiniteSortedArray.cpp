#include <iostream>

using namespace std;

/*

Find position of an element in an Infinite Sorted Array

Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

Since array is sorted, the first thing clicks into mind is binary search, but the problem here is
that we don’t know size of array.
If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order
to find position of key, first we find bounds and then apply binary search algorithm.

Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with
high index element,
-if it is greater than high index element then copy high index in low index and double the high index.
-if it is smaller, then apply binary search on high and low indices found.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/find-po...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...
*/

int FindPositionOfElement(int* arr, int n) {
	int start = 0, end = 1;

	while (arr[end] < n) {
		start = end;
		end = 2 * end;
	}


	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == n)
			return mid;

		if (arr[mid] < n) {
			// right sub-array
			start = mid + 1;
		}
		else {
			// left sub array
			end = mid - 1;
		}
	}

	return -1;
}

void testFindPositionOfElement() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int n = 17;
	int result = FindPositionOfElement(arr, n);

	cout << "Position of " << n << " in an Infinite Sorted Array: " << result << endl;
}