#include <iostream>

using namespace std;


int BinarySearchDscArray(int arr[], int size, int n) {
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == n)
			return mid;

		// search in left half
		if (arr[mid] < n)
			end = mid - 1;

		// otherwise: right half
		else
			start = mid + 1;
	}

	return -1;
}

void testBinarySearchDscArray() {
	int arr[] = { 9,8,7,6,5,3,1 };
	int size = 7;
	int n = 7;
	int ans = BinarySearchDscArray(arr, size, n);
	cout << n << " found at index: " << ans << endl;
}