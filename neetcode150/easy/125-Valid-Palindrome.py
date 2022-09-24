#!/usr/bin/python3

class Solution:
  def validPalindrome(self, s: str) -> bool:
    # Initialize front and back pointers
    f = 0
    b = len(s) - 1

    # Convert the given string to lowercase
    s = s.lower()

    while f < b:
      # Pass all characters that are not letters of the alphabet or digits 
      if not s[f].alpha() and not s[f].isdigit():
        f += 1
        continue
      if not s[b].alpha() and not s[b].isdigit():
        b -= 1
        continue
      # Check if character in the front equals character in the back
      if s[f] == s[b]:
        f += 1
        b -= 1
      else:
        # If the characters don't match then the word can not be a valid palindrome
        return False
    return True
