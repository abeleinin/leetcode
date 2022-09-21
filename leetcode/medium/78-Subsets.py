#!/usr/bin/python3
class Solution:
  # Backtracking Solution
  def subsets(self, nums: list) -> list:
    ans = []
    sub = []
    def dfs(i):
      if i >= len(nums):
        ans.append(sub.copy())
        return 
            
      sub.append(nums[i])
      dfs(i + 1)
            
      sub.pop()
      dfs(i + 1)
            
    dfs(0)
    return ans