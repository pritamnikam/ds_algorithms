#include <iostream>
#include <stack>
#include <vector>

using namespace std;

namespace {
	const int kMaxRows = 100;
	const int kMaxCols = 100;
}  // namespace

int LargestRectangleInHistogram(int arr[], int n);

int MaxAreaRectangleInbinaryMatrix(int* matrix[], int rows, int cols) {
	int arr[kMaxCols];
	int maxArea = 0;

	// row-compression: 2d to 1d: 
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (i == 0) {
				arr[i] = matrix[i][j];
			}
			else if (matrix[i][j] == 0) {
				arr[i] = 0;
			}
			else {
				arr[i] += 1;
			}
		}

		// calculate th maximum area in histogram
		int area = LargestRectangleInHistogram(arr, cols);
		if (maxArea < area)
			maxArea = area;
	}

	return maxArea;
}