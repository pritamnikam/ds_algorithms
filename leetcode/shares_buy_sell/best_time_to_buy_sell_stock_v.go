package main

import "fmt"

/*

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

309. Best Time to Buy and Sell Stock with Cooldown
Medium

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

/*
Dynamic Programming

dp[len][2]

i - length of prices array
j - possibilities -> buy '1' or not buy '0'

case 1: we have a stock onday i, dp[i][1] -> max of below

a. I bought it today
    dp[i-2][0] - price[i]   // (i - 2) -> cooldown of 1 day

b. I am carry forwarding
	dp[i-1][1]


case 2: We have no stock on day i, dp[i][0] -> max of below

a. I sold it today
   dp[i-1][1] + price[i]

b. I am carry forwarding, doing nothing
   dp[i-1][0]

*/

func maxProfit(prices []int) int {
	len := len(prices)

	if len <= 1 {
		return 0
	}

	if len == 2 && prices[1] > prices[0] {
		return prices[1] - prices[0]
	} else if len == 2 {
		return 0
	}

	dp := make([][]int, len)
	for i := range dp {
		dp[i] = make([]int, 2)
	}

	// do not have stock
	dp[0][0] = 0 // do nothing

	// have stock
	dp[0][1] = -prices[0] // buy stock

	// do not have stock
	dp[1][0] = Max(dp[0][0], dp[0][1]+prices[1]) // do nothing or sold stock

	// have stock
	dp[1][1] = Max(dp[0][1], dp[0][0]-prices[1]) // do nothing or buy stock

	for i := 2; i < len; i++ {

		// do not have stock
		dp[i][0] = Max(dp[i-1][1]+prices[i], dp[i-1][0]) // do nothing or sold

		// have stock
		dp[i][1] = Max(dp[i-2][0]-prices[i], dp[i-1][1]) // do nothing or buy
	}

	return dp[len-1][0]
}

func main() {
	profit := maxProfit([]int{1, 2, 3, 0, 2})
	fmt.Println("profit = ", profit)
}
