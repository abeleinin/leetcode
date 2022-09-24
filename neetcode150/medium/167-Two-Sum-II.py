#!/usr/bin/python3

class Solution:
  # Two pointer solution O(n) and O(1) space
  def twoSum(self, nums: list, target: int) -> list:
    i = 0
    j = len(nums) - 1

    while i < j:
      curr = nums[i] + nums[j]
      if curr == target:
        return [i + 1, j + 1]
      elif curr > target:
        j -= 1
      else:
        i += 1