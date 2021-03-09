package main

import (
	"fmt"
	"sort"
)

/*

By taking union w/o extra space
Algorithm :
1) Take the union of the input arrays ar1[] and ar2[].
2) Sort ar1[] and ar2[] respectively.
3) The median will be the last element of ar1[] + the first
   element of ar2[] divided by 2. [(ar1[n-1] + ar2[0])/2].
*/

func swap(a, b *int) {
	c := *a
	*a = *b
	*b = c
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	i := len(nums1) - 1
	j := 0
	// arr1 hold all elements lesser than that of arr2
	for nums1[i] > nums2[j] && i >= 0 && j < len(nums2) {
		swap(&nums1[i], &nums2[j])
		i -= 1
		j += 1
	}

	sort.Ints(nums1)
	sort.Ints(nums2)

	return (float64)(nums1[len(nums1)-1]+nums2[0]) / 2
}

// ------------------------------------------ //

/*

By comparing the medians of two arrays)
Algorithm :
1) Calculate the medians m1 and m2 of the input arrays ar1[]
   and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one
   of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one
   of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
*/

func median(arr []int) int {
	n := len(arr)
	if n%2 == 0 {
		return (arr[n/2] +
			arr[n/2-1]) / 2
	}
	return arr[n/2]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func getMedian(arr1, arr2 []int) int {
	n := len(arr1)

	// base cases: a
	if n <= 0 {
		return -1
	}

	// base cases: b
	if n == 1 {
		return (arr1[0] + arr2[0]) / 2
	}

	// base cases: c
	if n == 2 {
		return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2
	}

	m1 := median(arr1)
	m2 := median(arr2)

	if m1 == m2 {
		return m1
	}

	if m1 < m2 {
		if n%2 == 0 {
			return getMedian(arr1[n/2-1:],
				arr2[0:n/2+1])
		}

		return getMedian(arr1[n/2:],
			arr2[0:n/2+1])
	}

	if n%2 == 0 {
		return getMedian(arr1[0:n/2-1],
			arr2[n/2+1:])
	}

	return getMedian(arr1[0:n/2+1],
		arr2[n/2:])
}

func main() {
	median := findMedianSortedArrays([]int{1, 12, 15, 26, 38}, []int{2, 13, 17, 30, 45})
	fmt.Println(median)

	median2 := getMedian([]int{1, 12, 15, 26, 38}, []int{2, 13, 17, 30, 45})
	fmt.Println(median2)
}
