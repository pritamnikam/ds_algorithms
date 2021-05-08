#include <iostream>

using namespace std;

/*
0-1 Knapsack Problem solution using recursion(Overlapping Subproblems).

Example:
 Given weights and values of n items, put these items in a knapsack of capacity W
 to get the maximum total value in the knapsack. In other words, given two integer
 arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated
 with n items respectively
 
 Also given an integer W which represents knapsack capacity, find out the maximum
 value subset of val[] such that sum of the weights of this subset is smaller than
 or equal to W. You cannot break an item, either pick the complete item, or don’t
 pick it (0-1 property).

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/0-1-kna...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...
*/

int Knapsack(int wt[], int value[], int capacity, int size) {
	// base case:
	if (size == 0 || capacity == 0) {
		return 0;
	}

	// decision tree:
	int id = size - 1;
	if (wt[id] <= capacity) {
		int result_with = value[id] + Knapsack(wt, value, capacity - wt[id], size - 1);
		int result_without = Knapsack(wt, value, capacity, size - 1);

		return std::max(result_with, result_without);
	}

	return Knapsack(wt, value, capacity, size - 1);
}

void testKnapsack() {
	int wt[] = {1,3,4,5};
	int val[] = {1,4,5,7};
	int capacity = 7;
	int size = 4;

	int result = Knapsack(wt, val, capacity, size);
	cout << result << endl;
}