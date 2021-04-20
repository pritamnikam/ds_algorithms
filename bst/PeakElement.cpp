#include <iostream>

using namespace std;

/*
Peak Element

A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example :

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

PROBLEM STATEMENT LINK:https://leetcode.com/problems/find-pe...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...
*/

int PeakElement(int arr[], int size) {
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (mid > 0 && mid < size - 1) {
			if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
				return mid;
			} if (arr[mid] < arr[mid + 1]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		} else if (mid == 0 && arr[mid] < arr[mid+1]) {
			return mid;
		} else if (mid == 0) {
			start = mid + 1;
		} else if (mid == size - 1 && arr[mid] > arr[mid - 1]) {
			return mid;
		}
		else if (mid == size - 1) {
			end = mid - 1;
		}
	}

	return -1;
}

void testPeakElement() {

}