#include <iostream>

using namespace std;


/*
Next Alphabetical Element

Given an array of letters sorted in ascending order,
find the smallest letter in the the array which is greater
than a given key letter.

*/

int NextAlphabeticalElement(const char* str, int length, char ch) {
	int start = 0, end = length, result = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (str[mid] == ch) {
			result = mid + 1;
			return result;
		}

		if (str[mid] < ch) {
			// right sub-array
			start = mid + 1;
		}
		else {
			// left sub-array
			result = mid;
			end = mid - 1;
		}
	}

	return result;
}

void testNextAlphabeticalElement() {
	const char *str = "aabcdefg";
	int length = strlen(str);
	char ch = 'd';

	int result = NextAlphabeticalElement(str, length, ch);
	cout << "Next Alphabetical Element for " << ch << " is found at index: " << result << endl;
}