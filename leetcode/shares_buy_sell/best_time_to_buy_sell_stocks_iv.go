package main

import "fmt"

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

/*
188. Best Time to Buy and Sell Stock IV
Hard

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Notice that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


Constraints:

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxProfitNoLimitOnTransactions(prices []int) int {
	profit := 0

	for i := 0; i < len(prices)-1; i++ {
		if prices[i] < prices[i+1] {
			profit += (prices[i+1] - prices[i])
		}
	}

	return profit
}

func maxProfit(k int, prices []int) int {
	if k <= 0 || len(prices) <= 1 {
		// fmt.Println("input array length is zero")
		return 0
	}

	if k >= len(prices)/2 {
		// fmt.Println("input array length is less than required k")
		return maxProfitNoLimitOnTransactions(prices)
	}

	// buy / sell
	buy := make([]int, k)
	sell := make([]int, k)

	for i := 0; i < k; i++ {
		buy[i] = -100000
		sell[i] = 0
	}

	// for all prices
	for i := 0; i < len(prices); i++ {

		// for first k transactins
		for j := 0; j < k; j++ {

			// if it's the first buy
			l := -prices[i]
			if j != 0 {
				// amount left post buying at current price
				l = sell[j-1] - prices[i]
			}

			// compute the buying / selling
			buy[j] = Max(buy[j], l)
			sell[j] = Max(sell[j], buy[j]+prices[i])
		}
	}

	return sell[k-1]
}

func main() {
	fmt.Println("Hello world!")

	profit := maxProfit(2, []int{})
	fmt.Println(profit)

	profit = maxProfit(2, []int{2, 4, 1})
	fmt.Println(profit)

	profit = maxProfit(2, []int{3, 2, 6, 5, 0, 3})
	fmt.Println(profit)
}
