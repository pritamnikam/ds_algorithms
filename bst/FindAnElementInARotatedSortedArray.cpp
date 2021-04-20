#include <iostream>

using namespace std;

/*
FIND AN ELEMENT IN A ROTATED SORTED ARRAY:

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

PROBLEM STATEMENT LINK:https://leetcode.com/problems/search-...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...
*/

int BST(int arr[], int start, int end, int n) {
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == n)
			return mid;

		if (arr[mid] < n) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	return -1;
}

int FindMinimumElement(int arr[], int size) {
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		int prev = (mid + size - 1) % size;
		int next = (mid + 1) % size;

		if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
			return mid;
		}

		if (arr[mid] < arr[end]) {
			// right array is sorted
			end = mid - 1;
		}
		else {
			// left array is sorted.
			start = 1 + mid;
		}
	}

	return 0;
}

int FindElementInRotatedSortedArray(int arr[], int size, int n) {
	int pivot = FindMinimumElement(arr, size);
	int res = BST(arr, 0, pivot - 1, n);
	if (res == -1)
		res = BST(arr, pivot, size - 1,n);

	return res;
}

void testFindElementInRotatedSortedArray() {
	{
		int arr[] = { 6,7,8,9,1,2,3,4,5 };
		int size = 9;
		int result = FindElementInRotatedSortedArray(arr, size, 4);

		cout << "4 found at: " << result << endl;
	}

	{
		int arr[] = { 3, 4, 5, 6,7,8,9,1,2 };
		int size = 9;
		int result = FindElementInRotatedSortedArray(arr, size, 5);

		cout << "5 found at: " << result << endl;
	}
}
