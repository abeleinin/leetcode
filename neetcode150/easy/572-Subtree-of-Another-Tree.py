#!/usr/bin/python3
# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right
class Solution:
  # Initial Solution
  def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
    if not p and not q:
      return True
    elif not p or not q or p.val != q.val:
      return False
    else:
      return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
  def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
    if not root and not subRoot:
      return True
    if not root or not subRoot:
      return False
    else:
      return (self.isSameTree(root, subRoot) or 
              self.isSubtree(root.left, subRoot) or 
              self.isSubtree(root.right, subRoot))
