#!/bin/usr/python3

# Solution 1
class Solution:
  def permute(self, nums: list):
    res = []
    perm = []
    chosen = {}
    def search():
      if len(perm) == len(nums):
        res.append(perm.copy())
        return 
      for i in nums:
        if i in chosen: 
          continue
        chosen[i] = 1
        perm.append(i)
        search()
        del chosen[i]
        perm.pop()
    search()        
    return res
