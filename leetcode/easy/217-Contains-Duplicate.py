#!/usr/bin/python3

class Solution:
  def containsDuplicate(self, nums: list) -> bool:
    m = {}
    for n in nums:
      if n in m:
        return True
      m[n] = n
    return False
