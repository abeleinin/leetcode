#!/usr/bin/python3

class Solution:
  # Initial solution using sorting O(n)
  def longestConsecutive(self, nums: list) -> list:
    if len(nums) == 0:
      return 0
    
    nums = sorted(list(set(nums)))

    longest = 1
    curr = 1
    for i in range(len(nums) - 1):
      if nums[i] + 1 == nums[i + 1]:
        curr += 1 
        longest = max(longest, curr)
      else:
        curr = 1
    return longest

  # Using Dictionary
  def longestConsecutive(self, nums: list) -> int:
    h = {} 
    longest = 0
    for n in nums:
      h[n] = 0
        
    for i in range(len(nums)):
      if nums[i] - 1 not in h:
        curr = 1
        currNum = nums[i] + 1
        while currNum in h:
          curr += 1
          currNum += 1
        longest = max(longest, curr)

    return longest