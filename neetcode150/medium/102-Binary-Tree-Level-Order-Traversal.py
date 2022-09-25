#!/usr/bin/python3

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
  # Initial solution using Breath-First Search 
  def levelOrder(self, root: TreeNode):
    if root is None:
      return []
    res = []
    def bfs(node):
      q = []
      q.append(node)
      while q:
        size = len(q)
        level = []
        while size > 0:
          temp = q.pop(0)
          level.append(temp.val)
          size -= 1
          if temp.left:
            q.append(temp.left)
          if temp.right:
            q.append(temp.right)
        res.append(level)
    bfs(root)                
    return res

  # Slightly faster without extra function 
  def levelOrder(self, root: TreeNode):
    res = []
    if root is None:
      return res
    q = []
    q.append(root)
    while q:
      size = len(q)
      level = []
      for i in range(size):
        temp = q.pop(0)
        level.append(temp.val)
        if temp.left:
          q.append(temp.left)
        if temp.right:
          q.append(temp.right)
      res.append(level)
    return res