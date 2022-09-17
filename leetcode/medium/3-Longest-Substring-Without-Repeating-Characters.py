#!/usr/bin/python3

class Solution:
  # Inital solution O(n^2)
  def lengthOfLongestSubstring(self, s: str) -> int:
    curr = ""
    res = 0
    i = 0
    j = 1
    while j <= len(s):
      if s[j - 1] not in curr:
        curr = s[i:j]
        res = max(len(curr), res)
        j += 1
      else:
        curr = ""
        i += 1
        j = i + 1
    return res
  
  def lengthOfLongestSubstring(self, s: str) -> int:
    return 1