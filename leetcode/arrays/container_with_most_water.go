package main

import "fmt"

/**
11. Container With Most Water
Medium

https://leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an , where each represents a
point at coordinate (i, ai). n vertical lines are drawn such that the two
endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which,
together with the x-axis forms a container, such that the container contains
the most water.

Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section)
the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Example 3:
Input: height = [4,3,2,1,4]
Output: 16

Example 4:
Input: height = [1,2,1]
Output: 2


Constraints:
n == height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104


*/

func calculateArea(w, h int) int {
	return w * h
}

func maxArea(height []int) int {
	start := 0
	end := len(height) - 1

	max_area := 0
	for start < end {
		// fmt.Println("start, end -> ", start, end)
		h := 0
		w := end - start
		if height[start] < height[end] {
			h = height[start]
			start += 1
		} else {
			h = height[end]
			end -= 1
		}

		current_area := calculateArea(w, h)
		if max_area < current_area {
			max_area = current_area
		}
	}

	return max_area
}

func main() {
	result := maxArea([]int{1, 8, 6, 2, 5, 4, 8, 3, 7})
	fmt.Println("result: ", result)

	result = maxArea([]int{1, 1})
	fmt.Println("result: ", result)

	result = maxArea([]int{4, 3, 2, 1, 4})
	fmt.Println("result: ", result)

	result = maxArea([]int{1, 2, 1})
	fmt.Println("result: ", result)
}
