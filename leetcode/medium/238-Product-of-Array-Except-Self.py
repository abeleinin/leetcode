#!/usr/bin/python3
class Solution:
  # Prefix and Postfix solution O(n)
  def productExceptSelf(self, nums: list) -> list:
    n = len(nums)
    pre = [0] * n
    post = [0] * n
        
    pre[0] = 1
    for i in range(1, n):
      pre[i] = nums[i - 1] * pre[i - 1]
        
    post[n - 1] = 1
    for i in range(n-2, -1, -1):
      post[i] = nums[i + 1] * post[i + 1]
          
    s = [0] * n
    for i in range(n):
      s[i] = pre[i] * post[i]
        
    return s
  
  # Optimal Solution with O(n) runtime with O(1) space (output array doesn't count)
  def productExceptSelf(self, nums: list) -> list:
    res = [1] * len(nums)
        
    pre = 1
    for i in range(len(nums)):
      res[i] = pre 
      pre *= nums[i]
        
    post = 1
    for i in range(len(nums)-1, -1, -1):
      res[i] *= post 
      post *= nums[i]
            
    return res