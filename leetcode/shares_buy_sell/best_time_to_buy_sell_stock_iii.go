package main

import (
	"fmt"
)

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

/*
123. Best Time to Buy and Sell Stock III
Hard

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.


Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.


Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
Example 4:

Input: prices = [1]
Output: 0


Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

func Max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

func maxProfit(prices []int) int {
	var firstBuy int = -100000
	var firstSell int = 0

	var secondBuy int = -10000
	var secondSell int = 0

	for i := 0; i < len(prices); i++ {
		// if we are starting, the money let with us will be -price of stock
		firstBuy = Max(firstBuy, -prices[i])

		// If we sell the stock with present price, we will have the price with us that of buy + present day price.
		firstSell = Max(firstSell, firstBuy+prices[i])

		// Currently we will have the amount of money equals to firstSell.

		// Similarly, since we are buying we have to pay present stock price.
		secondBuy = Max(secondBuy, firstSell-prices[i])

		// recent amount of money we have i.e. secondBuy plus the prices of stock present day.
		secondSell = Max(secondSell, secondBuy+prices[i])
	}

	return secondSell
}

func main() {

	fmt.Println("Hello World!")

	profit := maxProfit([]int{})
	fmt.Println(profit)

	profit = maxProfit([]int{1, 2, 3, 4, 5, 6})
	fmt.Println(profit)

	profit = maxProfit([]int{7, 5, 4, 3, 2, 1})
	fmt.Println(profit)

	profit = maxProfit([]int{3, 3, 5, 0, 0, 3, 1, 4})
	fmt.Println(profit)
}
