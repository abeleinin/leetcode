#!/usr/bin/python3

class Solution:
  def twoSum(self, nums: list, target: int) -> list:
    m = {}

    for i, num in enumerate(nums):
      if num in m:
        return [m[num], i]
      m[target - num] = i
