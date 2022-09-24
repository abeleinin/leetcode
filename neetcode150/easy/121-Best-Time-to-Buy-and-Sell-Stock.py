#!/usr/bin/python3

class Solution:
  # Initial Solution: Using a two pointer sliding window
  def maxProfit(self, prices: list) -> int:
    profit = 0
    i = 0
    j = 1
    while j <= len(prices) - 1:
      # Set curr_min value and curr_max value
      # Inefficient variable setting here
      curr_min = prices[i]
      curr_max = prices[j]
      if curr_min > curr_max:
        # Move i to the new min value which is at index j
        i = j
        j += 1
      else:
        diff = curr_max - curr_min
        # Update to max profit
        if diff > profit:
          profit = diff
        # Only increment j because i is already at the min price
        j += 1
    return profit

  # One pointer for loop solution
  def maxProfit(self, prices: list)-> int:
    min_price = prices[0]
    profit = 0

    # Increment through all the prices
    for i in range(len(prices)):
      # Calculate curr_profit
      curr_profit = prices[i] - min_price
      # Update profit
      if curr_profit > profit:
        profit = curr_profit
      # Update min value
      if prices[i] < min_price:
        min_price = prices[i]

    return profit
