#!/usr/bin/python3
class Solution:
  # Initial Solution
  def maxDepth(self, root: list) -> int:
    if root:
      return max(self.maxDepth(root.left) + 1, self.maxDepth(root.right) + 1)
    else:
      return 1
  
  # Helper function solution
  def maxDepth(self, root: list) -> int:
    def height(node):
      if not node:
        return 0
      else:
        return max(height(node.left), height(node.right)) + 1
    return height(root)
