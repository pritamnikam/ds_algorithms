package main

import "fmt"

/*

3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:
Input: s = ""
Output: 0


Constraints:
0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.


s: a b c a b c b b  (r, c : range(s))
l: 0 0 0 1 2 3 3 4  (val, ok := mp[c] if (ok) max(l, 1 + val) else mp[c] = r)
r: 0 1 2 3 4 5 6 7

k: 1 2 3 3 3 3 3 3  (k:= (r - l + 1))

*/

func Max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func lengthOfLongestSubstring(s string) int {
	mp := make(map[rune]int, len(s))
	longest := 0
	left := 0

	for r, c := range s {
		value, ok := mp[c]
		if ok {
			left = Max(left, 1+value)
		}

		mp[c] = r
		longest = Max(longest, r-left+1)
	}

	return longest
}

func main() {
	t := lengthOfLongestSubstring("testagaintest")
	fmt.Println(t)
}
