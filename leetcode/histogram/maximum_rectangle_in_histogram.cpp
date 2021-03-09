#include <iostream>

#include <vector>
#include <stack>

using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/
/*
84. Largest Rectangle in Histogram
Hard

Given n non-negative integers representing the histogram's bar
height where the width of each bar is 1, find the area of largest
rectangle in the histogram.

Example:
Input: [2,1,5,6,2,3]
Output: 10
*/

class Solution {
public:
    int largestArea(int heights[], int n) {

        stack<int> st;

        int top;
        int area_with_top;
        int max_area = 0;

        int i = 0;
        while (i < n) {
            if (st.empty() ||
                heights[st.top()] <= heights[i]) {
                    st.push(i++);
                } else {
                    top = st.top();
                    st.pop();

                    area_with_top = heights[top] * (st.empty() ? i
                                                               : (i - st.top() - 1));

                     if (max_area < area_with_top) {
                        max_area = area_with_top;
                     }
                }
        }

        while (!st.empty()) {
            top = st.top();
            st.pop();

            area_with_top = heights[top] * (st.empty() ? i
                                                       : (i - st.top() - 1));

             if (max_area < area_with_top) {
                max_area = area_with_top;
             }
        }


        return max_area;
    }

};

int main() {

    {
        int arr[] = {2, 1, 2};
        int n = 3;

        Solution sol;
        int area = sol.largestArea(arr, n);
        cout << area << endl;
    }

    {
        int arr[] = {1, 2, 3, 4, 5, 6};
        int n = 6;

        Solution sol;
        int area = sol.largestArea(arr, n);
        cout << area << endl;

    }

    {
        int arr[] = {4, 4, 1, 3, 2, 6};
        int n = 6;

        Solution sol;
        int area = sol.largestArea(arr, n);
        cout << area << endl;

    }

    return 0;
}
