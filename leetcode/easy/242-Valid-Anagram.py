#!/usr/bin/python3

class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    if len(s) != len(t):
      return False

    h1 = {}
    h2 = {}

    for l in s:
      if l in h1:
        h1[l] += 1
      else:
        h1[l] = 1
  
    for l in t:
      if l in h2:
        h2[l] += 1
      else:
        h2[l] = 1
    
    return h1 == h2
