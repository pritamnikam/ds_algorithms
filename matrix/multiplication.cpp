#include <iostream>

using namespace std;

namespace {
	const int kRows = 10;
	const int kCols = 10;
}

void multiply(int m1[kRows][kCols],
	          int m2[kRows][kCols], 
	          int result[kRows][kCols], 
	          int r1, int c1, int r2, int c2) {
	if (c1 != r2)
		return;

	// for all rows of m1
	for (int i = 0; i < r1; ++i) {

		// for all columns in m2
		for (int j = 0; j < c2; ++j) {

			// for all rows of m2: 
			// # of cols of m1 == # of rows of m2
			for (int k = 0; k < r2; ++k) {

				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}