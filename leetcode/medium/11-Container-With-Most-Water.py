#!/usr/bin/python3
class Solution:
  # Initial solution 
  def maxArea(self, height: list) -> int:
    i = 0
    j = len(height) - 1
        
    if len(height) == 2:
      return min(height[i], height[j]) * 1
        
    res = 0
    while i < j:
      between = j - i
      curr = min(height[i], height[j]) * between
      if curr > res:
        res = curr
      if height[i] > height[j]:
        j -= 1
      else:
        i += 1
    return res

  # Optimal solution using Two Pointer technique
  def maxArea(self, height: list) -> int:
    i = 0
    j = len(height)

    length = j
    res = 0
    while length > 0:
      length = j - i
      if height[i] > height[j]:
        res = max(height[j] * length, res)
        j -= 1
      else:
        res = max(height[i] * length, res)
        i += 1
    return res

  