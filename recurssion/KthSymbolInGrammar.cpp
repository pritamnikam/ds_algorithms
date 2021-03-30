#include <iostream>

/*
* Kth Symbol in Grammar
* 
Problem Description: https://leetcode.com/problems/k-th-sy...​
On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

The Notes that I taught in the video and the Working Code (if any) will be available on my Patreon page under the "Notes, Code And Support" tier.

Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes: https://www.patreon.com/posts/38704577​

*/

int KthSymbolInGrammar(int N, int K) {
	if (N == 1 && K == 1) {
		return 0;
	}

	int length = std::pow(2, N-1);
	int mid = length / 2;

	if (K <= mid)
		return KthSymbolInGrammar(N - 1, K);

	return !KthSymbolInGrammar(N - 1, K - mid);
}

void testKthSymbolInGrammar() {
	int k = 3;
	int N = 4;

	int result = KthSymbolInGrammar(N, k);

	N = 3;
	k = 3;
	result = KthSymbolInGrammar(N, k);
}