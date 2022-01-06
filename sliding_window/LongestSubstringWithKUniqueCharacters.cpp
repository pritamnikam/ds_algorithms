#include <iostream>
#include <string>

using namespace std;

/*
Longest Substring With K Unique Characters | Variable Size Sliding Window

Become a Competitive Programming Hero with this structured batch to
help all levels of programmers sharpen their skills: http://unacademy.cc/AVBAT​


[FREE] Beginners lessons in programming by
Codechef: https://unacademy.com/a/beginner-spec...​


Patreon Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/45213007​

Playlist Link: https://youtube.com/playlist?list=PL_...​


Problem Description: https://practice.geeksforgeeks.org/pr...​

Given a string you need to print the size of the longest possible
substring that has exactly k unique characters.


Example:
Input:
2
aabacbebebe
3
aaaa
1
Output:
7
4

*/

#include <unordered_map>


int LongestSubstringWithKUniqueCharacters(string text, int k) {

	int n = text.size();
	int i = 0;
	int j = 0;
	int result = 0;
	unordered_map<char, int> mp;

	while (j < n) {
		// calculations
		mp[text[j]]++;

		// if it's less than the k unique char.
		if (mp.size() < k) {
			++j;
		}
		// meets the condition
		else if (mp.size() == k) {
			// get the answer
			result = max(result, j - i + 1);
			++j;
		}
		else { // otherwise: slide the window
			while (mp.size() > k) {
				mp[text[i]]--;
				if (mp[text[i]] == 0) {
					mp.erase(text[i]);
				}

				++i;
			}

			if (mp.size() == k) {
				// get the answer
				result = max(result, j - i + 1);
			}

			++j;
		}
	}

	return result;
}

void testLongestSubstringWithKUniqueCharacters() {
	string text = "aabacbebebe";
	int k = 3;
	int result = LongestSubstringWithKUniqueCharacters(text, k);
	cout << result << endl;

	text = "aaaa";
	k = 1;
	result = LongestSubstringWithKUniqueCharacters(text, k);
	cout << result << endl;
}