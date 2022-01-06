#include <iostream>

#include <string>
#include <unordered_map>

using namespace std;

/*
Minimum Window Substring  | Variable Size Sliding Window

Check out the batches here: https://unacademy.com/goal/competitiv...​

Check out all the free classes in the current week here: http://unacademy.cc/daily_learning​

Check out the Star Educators here: http://unacademy.cc/EducatorYT​

Prodigy 2021: Comprehensive Course to Become a Codechef certified Expert Programmer (C++): http://bit.ly/prodigyc​

Prodigy 2021: Comprehensive Course to Become a Codechef certified Expert Programmer (Python): http://bit.ly/prodigypython​

Prodigy 2021: Comprehensive Course to Become a Codechef certified Expert Programmer (Java): http://bit.ly/prodigyjava​


USE CODE ADITYA.VERMA.NITB for 10% off

---------------------------------------------------------------------------------------------------------------------------------------------------------------


Patreon Link: https://www.patreon.com/adityaVerma​​
Video Pdf Notes: https://www.patreon.com/posts/47535068​

Code will be uploaded with the its Code Video on 16 Feb 2020.

---------------------------------------------------------------------------------------------------------------------------------------------------------------



Playlist Link: https://www.youtube.com/playlist?list...​

Problem Description: https://leetcode.com/problems/minimum...​

Given two strings s and t, return the minimum window in s which will contain all 
the characters in t. If there is no such window in s that covers all characters in t, 
return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one
unique minimum window in s.



Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Example 2:

Input: s = "a", t = "a"
Output: "a"


Timestamps:
0:00​​ Intro and Flow
1:07​​ Problem Statement Input and Output
6:53​ Become a Champion in Coding with Unacademy
10:39​ Identification
12:07​​ Explanation
*/

string MinimumWindowSubstring(string text, string pattern) {
	unordered_map<char, int> mp;
	int i = 0, j = 0;
	int cardinality = 0;
	int n = text.size();
	int result = n;
	string str;

	// Preapre initial map.
	for (char ch : pattern) {
		mp[ch]++;
		if (mp[ch] == 1) {
			++cardinality;
		}
	}

	while (j < n) {
		// calculations:
		if (mp.find(text[j]) != mp.end()) {
			mp[text[j]]--;

			if (mp[text[j]] == 0) {
				--cardinality;
			}
		}

		// increment j for condition not met
		if (cardinality != 0) {
			++j;
		}

		// if we got the answer
		if (cardinality == 0) {
			
			while (cardinality == 0) {
				
				if (result > (j - i + 1)) {
					result = (j - i + 1);
					str = text.substr(i, result);
				}

				if (mp.find(text[i]) != mp.end()) {
					mp[text[i]]++;
					if (mp[text[i]] == 1) {
						++cardinality;
					}
				}

				++i;
			}
			
			++j;
		}
	}

	return str;
}

void testMinimumWindowSubstring() {
	string s = "ADOBECODEBANC", t = "ABC";
	string result = MinimumWindowSubstring(s, t);
	cout << result << endl;
}