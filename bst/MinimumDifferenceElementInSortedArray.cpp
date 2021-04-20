#include <iostream>

using namespace std;

/*
Minimum Difference Element in a Sorted Array

Given a sorted array, find the element in the array which has minimum difference with the given number.
*/

int MinimumDiffernceElement(int arr[], int size, int key) {
	int start = 0, end = size - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return arr[mid];
		if (arr[mid] < key) {
			// right sub-array
			start = mid + 1;
		}
		else {
			// left sub-array
			end = mid - 1;
		}
	}


	int result = abs(arr[start] - key);
	if (result > abs(arr[end] - key))
		return arr[end];
	return arr[start];
}

void testMinimumDiffernceElement() {
	int arr[] = { 1,2,3,4,5,7,8,9 };
	int key = 6;
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = MinimumDiffernceElement(arr, size, key);
	cout << "Minimum Difference Element in a Sorted Array : " << result << endl;
}