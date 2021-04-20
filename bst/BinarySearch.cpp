#include <iostream>

using namespace std;

int BinarySearch(int arr[], int size, int n) {
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == n) {
			return mid;
		}

		if (arr[mid] > n) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return -1;
}

void testBinarySearch() {
	int arr[] = { 1,3,5,6,7,8,9 };
	int size = 7;
	int n = 7;
	int ans = BinarySearch(arr, size , n);
	cout << n << " found at index: " << ans << endl;
}