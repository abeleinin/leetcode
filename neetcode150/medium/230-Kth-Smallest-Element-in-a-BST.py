from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.ans = -1
        self.c = 0

    def dfs(self, node, k):
        if node is None:
            return 
        self.dfs(node.left, k)
        self.c += 1
        if self.c == k:
            self.ans = node.val
            return 
        self.dfs(node.right, k)
        
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.dfs(root, k)
        return self.ans
        