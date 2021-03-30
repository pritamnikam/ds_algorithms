#include <iostream>

using namespace std;

/*

Tower of Hanoi | Recursion

The tower of Hanoi is a famous puzzle where we have three rods and N disks.
The objective of the puzzle is to move the entire stack to another rod.
You are given the number of discs N.

Initially, these discs are in the rod 1.
You need to print all the steps of discs movement so that all the discs
reach the 3rd rod. Also, you need to find the total moves.

Problem Description: https://practice.geeksforgeeks.org/pr...​

The Notes that I taught in the video and the Working Code (if any) will be available on my Patreon page under the "Notes, Code And Support" tier.

Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes: https://www.patreon.com/posts/38704739
*/

void Move(int n, int start, int destination) {
	cout << "Move " << n << " from " << start << " to " << destination << endl;
}

void TowerOfHanai(int n, int start, int end, int spare) {
	if (n == 1) {
		Move(n, start, end);
		return;
	}

	TowerOfHanai(n - 1, start, spare, end);

	Move(n, start, end);

	TowerOfHanai(n - 1, spare, end, start);
}

void testTowerOfHanai() {
	int n = 3, start = 1, end = 2, spare = 3;
	TowerOfHanai(n, start, end, spare);
}