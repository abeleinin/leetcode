#!/usr/bin/python3
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # Initial Solution (Brute force) O(n^2)
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
      def height(node):
        if not node:
          return 0
        else:
          return max(height(node.right), height(node.left)) + 1
      if not root:
        return 0
      else:
        b = height(root.left) + height(root.right)
        r = self.diameterOfBinaryTree(root.right)
        l = self.diameterOfBinaryTree(root.left)
        return max(b, l, r)

    # Optimal Solution O(n)
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
      res = [0] 
      def dfs(root):
        if not root:
          return -1
        left = dfs(root.left)
        right = dfs(root.right)
        res[0] = max(res[0], left + right + 2)

        return max(left, right) + 1
      dfs(root)
      return res[0]