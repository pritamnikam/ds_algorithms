/*
Sum of Elements between k1 smallest and k2 smallest numbers

Given an array of integers and two numbers k1 and k2.
Find the sum of all elements between given two k1’th and k2’th smallest elements of the array.
It may  be assumed that all elements of array are distinct.

Example :
Input : arr[] = {20, 8, 22, 4, 12, 10, 14},  k1 = 3,  k2 = 6
Output : 26
         3rd smallest element is 10. 6th smallest element
         is 20. Sum of all element between k1 & k2 is
         12 + 14 = 26
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int KthSmallestElement(int arr[], int n, int k);

int SumofElementsbetweenk1smallestandk2smallestnumbers(int arr[], int n, int k1, int k2) {
    int sum = 0;
    int k1smallest = KthSmallestElement(arr, n, k1);
    int k2smallest = KthSmallestElement(arr, n, k2);
    for (int i = 0; i < n; ++i) {
        if (arr[i] > k1smallest && arr[i] < k2smallest)
            sum += arr[i];
    }

    return sum;
}