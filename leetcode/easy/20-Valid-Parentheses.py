#!/usr/bin/python3

class Solution:
  # Stack based solution
  def isValid(self, s: str) -> bool:

    stack = []

    # Iterate through all paren in given string
    for l in s:
      # If its an opening paren add it to the top of the stack
      if l in ['(', '[', '{']:
        stack.append(l)
      # If the stack is empty return false
      elif not stack:
        return False
      # Check the top of the stack for the matching paren and remove
      # it from the stack
      elif l == ')' and stack[-1] == '(':
        stack.pop()
      elif l == ']' and stack[-1] == '[':
        stack.pop()
      elif l == '{' and stack[-1] == '{':
        stack.pop()
      else:
        return False
    # if the stack is empty and all paren's are valid return true
    # necessary to catch edge cases like "[" or "(("
    if len(stack) == 0:
      return True
    return False
