package main

import "fmt"

/**
167. Two Sum II - Input array is sorted
Easy

https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Given an array of integers numbers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.

You may assume that each input would have exactly one solution and you may not use the same element twice.



Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]


Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in increasing order.
-1000 <= target <= 1000
Only one valid answer exists
*/

func twoSum(numbers []int, target int) []int {
	n := len(numbers)
	left := 0
	right := n - 1

	for left < right {
		sum := numbers[left] + numbers[right]
		if sum == target {
			return []int{left + 1, right + 1}
		} else if sum < target {
			left += 1
		} else {
			right -= 1
		}
	}

	return []int{}
}

func main() {
	{
		numbers := []int{2, 7, 11, 15}
		target := 9
		x := twoSum(numbers, target)
		fmt.Println(x)
	}

	{
		numbers := []int{2, 3, 4}
		target := 6
		x := twoSum(numbers, target)
		fmt.Println(x)
	}

	{
		numbers := []int{-1, 0}
		target := -1
		x := twoSum(numbers, target)
		fmt.Println(x)
	}
}
