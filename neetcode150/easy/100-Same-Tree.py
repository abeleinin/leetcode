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
    def dfs(node1, node2):
      if node1 == None and node2 == None:
        return True
      if node1 == None or node2 == None:
        return False
      if node1.val != node2.val:
        return False
      left = dfs(node1.left, node2.left)
      right = dfs(node1.right, node2.right)
      return left and right
    return dfs(p, q)

  # Optimal solution
  def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
    if not p and not q:
      return True
    elif not p or not q or p.val != q.val:
      return False
    else:
      return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)