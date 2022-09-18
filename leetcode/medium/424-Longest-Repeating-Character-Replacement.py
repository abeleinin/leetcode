#!/usr/bin/python3

class Solution:
  # Intital solution
  def characterReplacement(self, s: str, k: int) -> int:
    freq = {}
    i = 0
    j = 0
    res = 0
    most = 0
    while j < len(s):
      length = j - i + 1 
      freq[s[j]] = freq.get(s[j], 0) + 1
      most = max(freq.values())
      if length - most <= k:
        res = max(length, res)
        j += 1
      else:
        freq[s[i]] -= 1
        freq[s[j]] -= 1
        i += 1
    return res
  
  # Cleaner O(26 * n) solution
  def characterReplacement(self, s: str, k: int) -> int:
    freq = {}
    res = 0
    l = 0
    for r in range(len(s)):
      freq[s[r]] = freq.get(s[r], 0) + 1
      most = max(freq.values()) 
      if r - l + 1 - most <= k:
        res = max(res, r - l + 1)
      else:
        freq[s[l]] -= 1
        l += 1
    return res 

  # O(n) solution using a maxFrequency variable
  def characterReplacement(self, s: str, k: int) -> int:
    freq = {}
    res = 0
    l = 0
    maxf = 0
    for r in range(len(s)):
      freq[s[r]] = freq.get(s[r], 0) + 1
      maxf = max(maxf, freq[s[r]])
      if r - l + 1 - maxf <= k:
        res = max(res, r - l + 1)
      else:
        freq[s[l]] -= 1
        l += 1
    return res 