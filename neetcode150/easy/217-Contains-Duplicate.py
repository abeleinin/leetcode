#!/usr/bin/python3

class Solution:
  # Solution 1: Using dictionaries
  def containsDuplicate(self, nums: list) -> bool:
    # Initialize a dictionary
    m = {}

    # Iterate through the values in the given list. If 
    # its already in the dictionary then we know theres
    # a duplicate. Otherwise we continue through the 
    # entire list.
    for n in nums:
      if n in m:
        return True
      m[n] = n
    return False

  # Solution 2: Using sets
  def containsDuplicate(self, nums: list) -> bool:
    s = set(nums)
    return not len(s) == len(nums)
