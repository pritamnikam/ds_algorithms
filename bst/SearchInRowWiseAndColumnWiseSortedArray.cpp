#include <iostream>

using namespace std;

/*
Search in Row wise And Column wise Sorted Array

Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. 
Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. 
The designed algorithm should have linear time complexity.
Example :

Input : mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
              x = 29
Output : Found at (2, 1)

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/search-...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...

*/

typedef std::pair<int, int> pair_i;

pair_i Search(int matrix[4][4], int rows, int cols, int key) {
    int i = 0;
    int j = cols - 1;

    while (i >= 0 && i < rows && j >= 0 && j < cols) {
        if (key == matrix[i][j]) {
            return std::make_pair(i, j);
        }

        if (key < matrix[i][j]) {
            // left
            --j;
        }

        if (key > matrix[i][j]) {
            // right
            ++i;
        }
    }

    return make_pair(-1, -1);
}

void testSearchInRowWiseAndColumnWiseSortedArray() {
    int mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50} };
    int x = 29;

    pair_i pii = Search(mat, 4, 4, x);
    cout << "Search in Row wise And Column wise Sorted Array: " << pii.first << ", " << pii.second << endl;
}