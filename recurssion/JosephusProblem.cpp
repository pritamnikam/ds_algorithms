#include <iostream>

#include <string>
#include <vector>

using namespace std;

/*

Josephus Problem | Game of Death in a circle | Execution in Circle

Patreon Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/39839473​

IBH Video: https://youtu.be/Xu5RqPdABRE​
Sort an Array Using Recursion: https://youtu.be/AZ4jEY_JAVc​

Problem Description: https://practice.geeksforgeeks.org/pr...​


There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed.
The counting begins at point 1 in the circle and proceeds around the circle in a fixed
direction (clockwise). In each step, a certain number of people are skipped and the next
person is executed. The elimination proceeds around the circle (which is becoming smaller
and smaller as the executed people are removed), until only the last person remains, who
is given freedom.

Given the total number of persons n and a number k which indicates that k-1 persons are
skipped and kth person is killed in circle. The task is to choose the place in the initial
circle so that you are the last one remaining and so survive.

Consider if n = 5 and k = 2, then the safe position is 3.
Firstly, the person at position 2 is killed, then person at position 4 is killed, then
person at position 1 is killed. Finally, the person at position 5 is killed. So the person
at position 3 survives.


*/

void GameOfDeathInCircle(vector<int> arr, int k, int index, int& answer) {
	if (arr.size() == 1) {
		answer = arr[0];
		return;
	}

	int id = (index + k) % arr.size();
	arr.erase(arr.begin() + id);

	GameOfDeathInCircle(arr, k, id, answer);
}

void testGameOfDeathInCircle() {
	vector<int> arr = { 1, 2, 3, 4, 5 };
	int k = 3;
	int index = 0;
	int answer = 0;

	GameOfDeathInCircle(arr, k-1, index, answer);
}