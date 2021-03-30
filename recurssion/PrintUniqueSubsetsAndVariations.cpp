#include <iostream>


/*
Print unique subsets And Variations

Link: https://www.patreon.com/adityaVerma​
Video Pdf Notes And Code: https://www.patreon.com/posts/38828164​

Problem Description: https://practice.geeksforgeeks.org/pr...​

Given an array of integers that might contain duplicates,
return all possible subsets.

Note:

        Elements in a subset must be in non-descending order.
        The solution set must not contain duplicate subsets.
        The subsets must be sorted lexicographically.


*/

#include <string>
#include <unordered_map>

using namespace std;

void PrintUniqueSubsets(string input, string output, unordered_map<string, bool>& mp) {
    if (input.empty() && mp.find(output) != mp.end()) {
        mp[output] = true;
        cout << output << endl;
        return;
    }

    string output1 = output;
    string output2 = output;
    output2.push_back(input[0]);
    input.erase(input.begin() + 0);

    PrintUniqueSubsets(input, output1, mp);
    PrintUniqueSubsets(input, output2, mp);
}

void testPrintUniqueSubsets() {
    unordered_map<string, bool> mp;
    string input = "abca";
    string output = "";

    PrintUniqueSubsets(input, output, mp);
}