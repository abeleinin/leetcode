#!/usr/bin/python3
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  # Solution using dfs O(n)
  def isValidBST(self, root: TreeNode) -> bool:
    def dfs(node, left, right):
      if not node:
        return True
      # Check if the inequality is true (left < node.val < right)
      if not(node.val > left and node.val < right):
        return False
      return dfs(node.left, left, node.val) and dfs(node.right, node.val, right)
        
    return dfs(root, float("-inf"), float("inf"))