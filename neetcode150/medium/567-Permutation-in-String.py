#!/usr/bin/python3

class Solution:
  # Inital solution 
  def checkInclusion(self, s1: str, s2: str) -> bool:
    if len(s1) > len(s2):
      return False

    freq = {}

    for c in s1:
      freq[c] = freq.get(c, 0) + 1
    
    i = 0
    j = len(s1)

    while j <= len(s2):
      curr = {}
      for l in range(j - i):
        curr[s2[i + l]] = curr.get(s2[i + l], 0) + 1
      if freq == curr:
        return True
      i += 1
      j += 1
    return False

  # Optimal solution O(n)
  def checkInclusion(self, s1: str, s2: str) -> bool:
    if len(s1) > len(s2):
      return False
        
    s1freq, s2freq = [0] * 26, [0] * 26
        
    for i in range(len(s1)):
      s1freq[ord(s1[i]) - ord('a')] += 1
      s2freq[ord(s2[i]) - ord('a')] += 1
            
    match = 0
    for i in range(26):
      if s1freq[i] == s2freq[i]:
        match += 1
                
    l = 0
    for r in range(len(s1), len(s2)):
      if match == 26:
        return True
            
      index = ord(s2[r]) - ord('a')
      s2freq[index] += 1
      if s1freq[index] == s2freq[index]:
        match += 1
      elif s1freq[index] + 1 == s2freq[index]:
        match -= 1
                
      index = ord(s2[l]) - ord('a')
      s2freq[index] -= 1
      if s1freq[index] == s2freq[index]:
        match += 1
      elif s1freq[index] - 1 == s2freq[index]:
        match -= 1
      l += 1
            
    return match == 26
  