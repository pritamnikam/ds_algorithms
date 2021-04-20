#include <iostream>

using namespace std;

int BinarySearch(int arr[], int size, int n);
int BinarySearchDscArray(int arr[], int size, int n);

int BinarySearchOrderNotKnown(int arr[], int size, int n) {
	if (size == 1) {
		return arr[0] == n ? 0 : -1;
	}

	if (arr[0] < arr[size - 1]) {
		return BinarySearch(arr, size, n);
	}

	return BinarySearchDscArray(arr, size, n);
}

void testBinarySearchOrderNotKnown() {
	{
		int arr[] = { 1,3,5,6,7,8,9 };
		int size = 7;
		int n = 7;
		int ans = BinarySearchOrderNotKnown(arr, size, n);
		cout << n << " found at index: " << ans << endl;
	}


	{
		int arr[] = { 9,8,7,6,5,3,1 };
		int size = 7;
		int n = 7;
		int ans = BinarySearchOrderNotKnown(arr, size, n);
		cout << n << " found at index: " << ans << endl;

	}
}