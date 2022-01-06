#include <iostream>
#include <vector>
#include <list>

using namespace std;


/*

Maximum of all subarrays of size k  | Sliding Window

Given an array arr[] of size N and an integer K.
Find the maximum for each and every contiguous subarray of size K.

Example:

Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]

Problem Description:
    https://www.interviewbit.com/problems/sliding-window-maximum/#


*/

vector<int> MaximumOfAllSubarraysOfSizeK(int arr[], int n, int k) {

    int i = 0;
    int j = 0;
    vector<int> answer;
    list<int> l;

    while (j < n) {
        // 1. Calculations:
        while (!l.empty() && l.front() < arr[j]) {
            l.pop_back();
        }

        l.push_back(arr[j]);

        // 2. until we get the window slide:
        if (j - i + 1 < k) {
            j++;
        }
        else {
            // 3. Get the answer from calculations
            answer.push_back(l.front());

            // 4. Slide the window
            // 4a. Undo the ith calculations
            if (l.front() == arr[i]) {
                l.pop_front();
            }

            // 4b. slide: Move pointers forward.
            i++;
            j++;

        }
    }

    return answer;
}

void testMaximumOfAllSubarraysOfSizeK() {
    int n = 8;
    int arr[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;


    vector<int> answer = MaximumOfAllSubarraysOfSizeK(arr, n, k);
}