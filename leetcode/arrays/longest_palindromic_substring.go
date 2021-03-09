package main

import "fmt"

/*

LeetCode 5. Longest Palindromic Substring
Medium

https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, return the longest palindromic substring in s.


Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"


Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),

*/

func expandAroundCenter(s string, start, end int) int {
	for start >= 0 && end < len(s) && s[start] == s[end] {
		start -= 1
		end += 1
	}

	return end - start - 1
}

func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}

	start := 0
	end := 0
	odd_length := 0
	even_length := 0

	for k, _ := range s {
		odd_length = expandAroundCenter(s, k, k)
		even_length = expandAroundCenter(s, k, k+1)

		result_len := odd_length
		if odd_length < even_length {
			result_len = even_length
		}

		if result_len > (end - start) {
			start = k - ((result_len - 1) / 2)
			end = k + (result_len / 2)
		}
	}

	return s[start : end+1]
}

func main() {
	str := longestPalindrome("babad")
	fmt.Println(str)

	str = longestPalindrome("cbbd")
	fmt.Println(str)

	str = longestPalindrome("a")
	fmt.Println(str)

	str = longestPalindrome("ac")
	fmt.Println(str)
}
