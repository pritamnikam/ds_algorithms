#include <iostream>

#include <string>
#include <unordered_map>

using namespace std;

/*
Longest Substring With Without Repeating Characters | Variable Size Sliding Window

Learn about the course from our Educator: https://www.youtube.com/watch?v=CAWFa...​

Check out Unacademy's batch schedule and details here: https://unacademy.com/batch/summit-co...​


USE CODE ADITYA.VERMA.NITB for 10% off

Subscribe here for access to all content : https://unacademy.com/goal/competitiv...​

---------------------------------------------------------------------------------------------------------------------------------------------------------------


Patreon Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/45497463​

---------------------------------------------------------------------------------------------------------------------------------------------------------------



Playlist Link: https://youtube.com/playlist?list=PL_...​

Problem Description: https://leetcode.com/problems/longest...​

Given a string s, find the length of the longest substring without repeating characters.


Example:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring


Timestamps:
0:00​ Intro and Flow
1:04​ Problem Statement
4:39​ Become a Champion in Coding with Unacademy
8:01​ Input and Output
10:55​ Relation to Previous Problem
15:59​ Explanation and Approach
23:18​ Code
27:47​ Support the Channel: Like and Subscribe
*/

int LongestSubstringWithAllUniqueCharacters(string text) {

	int n = text.size();
	int j = 0; 
	int i = 0;
	unordered_map<char, int> mp;
	int result = 0;

	while (j < n) {
		mp[text[j]]++;
		int k = j - i + 1;

		

		if (mp.size() == k) {
			result = max(result, k);
			++j;
		}
		else {
			while (mp.size() < k) {
				mp[text[i]]--;
				if (mp[text[i]] == 0) {
					mp.erase(text[i]);
				}

				++i;
				k = (j - i) + 1;
			}

			if (mp.size() == k) {
				result = max(result, k);
			}

			++j;
		}
	}

	return result;
}

void testLongestSubstringWithAllUniqueCharacters() {
	string s = "pwwkew";
	int result = LongestSubstringWithAllUniqueCharacters(s);
	cout << result << endl;
}