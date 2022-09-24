#!/usr/bin/python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # Recursive Solution
    def invertTree(self, root: list) -> list:
      if root:
        right = root.right
        root.right = root.left
        root.left = right
        self.invertTree(root.right)
        self.invertTree(root.left)
        return root
    
        