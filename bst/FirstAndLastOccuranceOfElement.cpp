#include <iostream>

using namespace std;

/*
FIND FIRST AND LAST POSITIONS OF AN ELEMENT IN A SORTED ARRAY:

Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example:

Input : arr[] = {1, 3, 5, 5, 5, 5 ,67, 123, 125}
		x = 5
Output : First Occurrence = 2
		 Last Occurrence = 5

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/find-fi...?
PLAYLIST LINK:https://www.youtube.com/playlist?list...

*/

int LastOccuranceOfElement(int arr[], int size, int n) {
	int start = 0;
	int end = size - 1;
	int res = -1;

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


int FirstOccuranceOfElement(int arr[], int size, int n) {
	int start = 0;
	int end = size - 1;
	int res = -1;

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

void testFirstAndLastOccuranceOfElement() {
	int arr[] = { 1,2,3,5,5,5,5, 7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int n = 5;

	int first = FirstOccuranceOfElement(arr, size, n);
	int last = LastOccuranceOfElement(arr, size, n);

	cout << "First occurance: " << first << " and last occurance: " << last << endl;
}
