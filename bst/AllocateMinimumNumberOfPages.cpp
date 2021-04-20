#include <iostream>

using namespace std;

/*

Allocate Minimum Number Of Pages

Given number of pages in n different books and m students.
The books are arranged in ascending order of number of pages.
Every student is assigned to read some consecutive books.
The task is to assign books in such a way that the maximum number
of pages assigned to a student is minimum.

Example :

Input : pages[] = {12, 34, 67, 90}
        m = 2
Output : 113
Explanation:
There are 2 number of students. Books can be distributed
in following fashion :
  1) [12] and [34, 67, 90]
      Max number of pages is allocated to student
      2 with 34 + 67 + 90 = 191 pages
  2) [12, 34] and [67, 90]
      Max number of pages is allocated to student
      2 with 67 + 90 = 157 pages
  3) [12, 34, 67] and [90]
      Max number of pages is allocated to student
      1 with 12 + 34 + 67 = 113 pages

Of the 3 cases, Option 3 has the minimum pages = 113.

PROBLEM STATEMENT LINK:https://www.geeksforgeeks.org/allocat...​
PLAYLIST LINK:https://www.youtube.com/playlist?list...


Leetcode Problems that can be solved with the same approach :
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
https://leetcode.com/problems/split-array-largest-sum/

Related Problems For Practice :
Book Allocation Problem (GFG)
Aggressive cow (spoj)
Prata and roti (spoj)
EKO (spoj)
Google kickstart A Q-3 2020
*/

bool IsValid(int arr[], int size, int k, int mid) {
    int student = 1;
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum = sum + arr[i];
        if (sum > mid) {
            ++student;

            sum = arr[i];
        }
    }

    return student == k;
}

int Max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}


int  Sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum = sum + arr[i];

    return sum;
}

int AllocateMinimumNumberOfPages(int arr[], int size, int k) {
    int start = Max(arr, size);
    int end = Sum(arr, size);
    int result = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (IsValid(arr, size, k, mid)) {
            // left sub array
            result = mid;
            end = mid - 1;
        }
        else {
            // right sub array
            start = 1 + mid;
        }
    }
   
    return result;
}

void testAllocateMinimumNumberOfPages() {
    int pages[] = { 12, 34, 67, 90 };
    int k = 2;
    int size = sizeof(pages) / sizeof(pages[0]);
    int result = AllocateMinimumNumberOfPages(pages, size, k);
    cout << "Allocate Minimum Number Of Pages: " << result << endl;
}