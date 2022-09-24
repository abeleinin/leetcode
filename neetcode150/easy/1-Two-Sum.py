#!/usr/bin/python3

class Solution:
  def twoSum(self, nums: list, target: int) -> list:
    # Initialize a dictionary
    m = {}

    # enumerate build-in function keeps track of iterations
    # which we use to represent the index of each number from
    # the list.
    for i, num in enumerate(nums):
      # Check if the number is already in the dictionary
      if num in m:
        # Return the indexs at the first value 
        return [m[num], i]
      # Store the difference between the target and number to
      # keep track of the number needed to solve the problem.
      m[target - num] = i
