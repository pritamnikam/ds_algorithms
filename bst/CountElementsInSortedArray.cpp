#include <iostream>

using namespace std;
/*
COUNT NUMBER OF OCURRENCES(or frequency) IN A SORTED ARRAY:

Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. Expected time complexity is O(Logn)
Examples:

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
  Output: 4 // x (or 2) occurs 4 times in arr[]

  Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3
  Output: 1

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/count-n...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...
*/

int _FirstOccuranceOfElement(int arr[], int size, int n) {
	int start = 0;
	int end = size - 1;
	int res = 0;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == n) {
			res = mid;
			end = mid - 1;
		}
		else if (arr[mid] > n) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return res;
}

int _LastOccuranceOfElement(int arr[], int size, int n) {
	int start = 0;
	int end = size - 1;
	int res = 0;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == n) {
			res = mid;
			start = mid + 1;
		}
		else if (arr[mid] > n) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return res;
}

void testCountElementsInSortedArray() {
	int arr[] = { 1,2,3,5,5,5,5, 7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int n = 5;

	int first = _FirstOccuranceOfElement(arr, size, n);
	int last = _LastOccuranceOfElement(arr, size, n);

	cout << "Count of " << n << " in arr: " << (last - first) + 1 << endl;
}