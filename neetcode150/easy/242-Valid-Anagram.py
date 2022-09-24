#!/usr/bin/python3

class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    # Check if the two strings are equivalent lengths
    if len(s) != len(t):
      return False

    # Initialize two dictionaries to store the frequency 
    # of each letter in the given strings
    h1 = {}
    h2 = {}

    # Add the letters of string s to the dictionary h1
    for l in s:
      if l in h1:
        h1[l] += 1
      else:
        h1[l] = 1
  
    # Add the letters of string t to the dictionary h2
    for l in t:
      if l in h2:
        h2[l] += 1
      else:
        h2[l] = 1
    
    # Check if the two dictinaries are equivalent
    return h1 == h2
