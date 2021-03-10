/*
Frequency Sort

Print the elements of an array in the increasing frequency if 2 numbers
have same frequency then print the one which came first.

Example:
Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6}
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> FrequencySort(int arr[], int n) {
	unordered_map<int, int> map;
	for (int i = 0; i < n; ++i)
		map[arr[i]]++;

	priority_queue<pair<int, int>> heap;
	for (auto it = map.begin(); it != map.end(); ++it)
		heap.push(make_pair(it->second, it->first));

	vector<int> out;
	while (!heap.empty()) {
		int count = heap.top().first;
		int element = heap.top().second;
		for (int i = 0 ; i < count; ++i)
			out.push_back(element);

		heap.pop();
	}

	return out;
}