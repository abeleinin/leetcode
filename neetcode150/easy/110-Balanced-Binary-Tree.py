#!/usr/bin/python3
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # Initial recursive solution O(n^2)
    def isBalanced(self, root: TreeNode) -> bool:
      def height(node):
        if not node:
          return 0
        else:
           return max(height(node.left), height(node.right)) + 1
      if not root:
        return True
      if abs(height(root.left) - height(root.right)) > 1:
        return False
      else:
        return self.isBalanced(root.left) and self.isBalanced(root.right)

    # Helper function solution using dfs
    res = True
    def dfs(self, node):
      if not node:
        return 0
      left = self.dfs(node.left)
      right = self.dfs(node.right)

      if abs(left - right) > 1:
        self.res = False 

      return max(left, right) + 1
    def isBalanced(self, root: TreeNode) -> bool:
      self.dfs(root)
      return self.res
