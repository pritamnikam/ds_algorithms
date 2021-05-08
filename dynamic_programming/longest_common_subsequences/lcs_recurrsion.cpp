#include <iostream>
#include <string>

using namespace std;

/*

Introduction to Longest Common Subsequence Problem(LCS)
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them.
  A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/longest...​

Playlist Link: https://www.youtube.com/watch?v=nqowU...

*/

int LCS(const string& str1, const string& str2, int length1, int length2) {
	if (length1 || length2)
		return 0;

	if (str1[length1 - 1] == str2[length2 - 1])
		return 1 + LCS(str1, str2, length1 - 1, length2 - 1);

	return max(LCS(str1, str2, length1 - 1, length2), 
		       LCS(str1, str2, length1, length2 - 1));
}

void testLCSRecurrsion() {

}