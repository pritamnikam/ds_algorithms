package main

/*
https://leetcode.com/problems/add-two-numbers/

2. Add Two Numbers
Medium

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func NewNode(val int) *ListNode {
	return &ListNode{
		Val:  val,
		Next: nil,
	}
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var val1 int = 0
	var val2 int = 0
	var carry int = 0
	var sum int = 0

	sumHead := NewNode(-1)
	ptr := sumHead

	for l1 != nil || l2 != nil {
		if l1 != nil {
			val1 = l1.Val
			l1 = l1.Next
		} else {
			val1 = 0
		}

		if l2 != nil {
			val2 = l2.Val
			l2 = l2.Next
		} else {
			val2 = 0
		}

		sum = val1 + val2 + carry
		carry = sum / 10
		sum = sum % 10

		temp := NewNode(sum)
		ptr.Next = temp
		ptr = temp
	}

	if carry != 0 {
		temp := NewNode(carry)
		ptr.Next = temp
		ptr = temp
	}

	return sumHead.Next
}
