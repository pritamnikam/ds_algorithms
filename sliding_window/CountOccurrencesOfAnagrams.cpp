#include <iostream>

#include <string>
#include <unordered_map>

using namespace std;

/*
Count Occurrences Of Anagrams | Sliding Window

Given a word pat and a text txt. Return the count of the occurences
of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
*/

int CountOccurrencesOfAnagrams(string str, string pattern) {
	int cardinality = 0;
	unordered_map<char, int> charmap;
	for (int i = 0; i < pattern.length(); ++i) {
		charmap[pattern[i]]++;
		if (charmap[pattern[i]] == 1)
			++cardinality;
	}

	int i = 0;
	int j = 0;
	int k = pattern.length();
	int answer = 0;

	while (j < str.length()) {
		// 1. Calculations
		if (charmap.find(str[j]) != charmap.end()) {
			charmap[str[j]]--;

			// reduce cardinality
			if (charmap[str[j]] == 0)
				--cardinality;
		}

		// 2. Window size
		if (j - i + 1 < k) {
			++j;
		}
		else {
			// 3. Compute answer:
			// cardinality reaches to 0, we found the pattern
			if (cardinality == 0) {
				++answer;
			}

			// 4. Slide the window
			// restore the effect of i.
			if (charmap.find(str[i]) != charmap.end()) {
				charmap[str[i]]++;
				if (charmap[str[i]] == 1)
					++cardinality;
			}

			// now, slide.
			++i;
			++j;
		}
	}

	return answer;
}

void testCountOccurrencesOfAnagrams() {
	// output: 3
	{
		string text = "forxxorfxdofr";
		string pattern = "for";

		int answer = CountOccurrencesOfAnagrams(text, pattern);
		cout << answer << endl;
	}


	// output: 4
	{
		string text = "aabaabaa";
		string pattern = "aaba";

		int answer = CountOccurrencesOfAnagrams(text, pattern);
		cout << answer << endl;
	}

}