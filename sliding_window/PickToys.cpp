#include <iostream>

using namespace std;

/*
Pick Toys | An Interesting Sliding Window Problem

Use Code  ADITYA.VERMA.NITB  for unlocking Free Classes and 10% off in Subscription

Get ready to conquer the fundamentals and interviews with Unacademy's CONQUEST 2021.
Leave Procrastination behind in 2020 and enroll!

Check out "CONQUEST 2021: From programming fundamentals to Career Readiness (C++)" (Preview available)
: https://unacademy.com/batch/conquest-...​

Check out "CONQUEST 2021: From programming fundamentals to Career Readiness (PYTHON)" (Preview available)
: https://unacademy.com/batch/conquest-...​

Check out "CONQUEST 2021: From programming fundamentals to Career Readiness (JAVA)" (Preview available)
:https://unacademy.com/batch/conquest-...​


Be placement ready with our Tech Placement Bootcamp: https://unacademy.com/a/tech-placemen...​

---------------------------------------------------------------------------------------------------------------------------------------------------------------


Patreon Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/45753532​

---------------------------------------------------------------------------------------------------------------------------------------------------------------

Playlist Link: https://youtube.com/playlist?list=PL_...​


Problem Description: No Where, it was an interview problem

John is at a toy store help him pick maximum number of toys. He can only select in a
continuous manner and he can select only two types of toys.


Example:
Input:
1
abaccab




⏰ Time Stamps ⏰
0:00​ Intro and Flow
1:04​ Problem Statement
5:12​ Check out Unacademy's Free Courses
7:47​ Input and Output
10:33​ Explanation
18:16​ Relation to an already solved Problem
23:16​  Support the Channel: Like and Subscribe

*/

#include <unordered_map>

int PickToy(string str) {
	int k = 2;
	int i = 0, j = 0;
	unordered_map<char, int> mp;
	int n = str.size();
	int result = 0;
	while (j < n) {
		mp[str[j]]++;

		if (mp.size() < k) {
			++j;
		}
		else if (mp.size() == k) {
			result = max(result, j - i + 1);
			++j;
		}
		else {
			while (mp.size() > k) {
				mp[str[i]]--;
				if (mp[str[i]] == 0) {
					mp.erase(str[i]);
				}

				++i;
			}
			if (mp.size() == k) {
				result = max(result, j - i + 1);
			}
			++j;
		}
	}

	return result;
}

void testPickToy() {
	string str = "abaccab";
	int result = PickToy(str);
	cout << result << endl;
}