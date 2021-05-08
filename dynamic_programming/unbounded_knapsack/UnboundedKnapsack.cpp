#include <iostream>

using namespace std;

/*
Unbounded Knapsack (Repetition of items allowed)
 Given a knapsack weight W and a set of n items with certain value vali and weight wti,
 we need to calculate minimum amount that could make up this quantity exactly.
 
 This is different from classical Knapsack problem, here we are allowed to use unlimited number 
 of instances of an item.

Examples:

Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/unbound...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...
*/

namespace {
    const int kSize = 100;
    const int kCapacity = 1000;

    int dp[kSize][kCapacity];
}

int UnboundedKnapsack(int wt[], int value[], int size, int capacity) {
    for (int i = 0; i <= size; ++i)
        dp[i][0] = 0;

    for (int j = 1; j <= capacity; ++j)
        dp[0][j] = 0;

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= capacity; ++j) {
            if (wt[i - 1] < j) {
                dp[i][j] = max(dp[i - 1][j], value[i - 1] + dp[i][j - wt[i-1]]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[size][capacity];
}

void testUnboundedKnapsack() {
    int W = 100,
        val[] = { 1, 30 },
        wt[] = { 1, 50 },
        size = 2;

    int result = UnboundedKnapsack(wt, val, size, W);
    cout << result << endl;
}