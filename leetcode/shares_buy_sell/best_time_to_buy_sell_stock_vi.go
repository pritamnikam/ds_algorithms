package main

import "fmt"

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

714. Best Time to Buy and Sell Stock with Transaction Fee
Medium

Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.



dp[length][2]

i - Total number of days
j - buy or do not buy

Case 1: I have a stock on day i, dp[i][1] -> max of below
 a. I bought it today
    dp[i][1] = dp[i-1][0] - prices[i] - fee

 b. I am carrying a pre-bought stock. Doing nothing today.
    dp[i][1] = dp[i-1][0]

Case 2: I dont have stock on day i, dp[i][0] -> max of
 a. I sell it today
   dp[i][0] = dp[i-1][1] + prices[i]

 b. I am  carrying a pre-bought stock. Doing nothing today.const
   dp[i][0] = dp[i-1][0]
*/

func Max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func maxProfit(prices []int, fee int) int {
	len := len(prices)

	if len <= 1 {
		return 0
	}

	dp := make([][]int, len)
	for i := range dp {
		dp[i] = make([]int, 2)
	}

	dp[0][0] = 0
	dp[0][1] = -prices[0] - fee

	for i := 1; i < len; i++ {
		dp[i][0] = Max(dp[i-1][0], dp[i-1][1]+prices[i])
		dp[i][1] = Max(dp[i-1][1], dp[i-1][0]-prices[i]-fee)
	}

	return dp[len-1][0]
}

func main() {
	profit := maxProfit([]int{1, 3, 2, 8, 4, 9}, 2)
	fmt.Println(profit)
}
