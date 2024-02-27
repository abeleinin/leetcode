# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self):
        self.c = 0
    def dfs(self, node, rv):
        if node is None:
            return
        
        if node.val >= rv:
            self.c += 1
            rv = node.val

        self.dfs(node.left, rv)
        self.dfs(node.right, rv)

        return

    def goodNodes(self, root: TreeNode) -> int:
        self.dfs(root, root.val)
        return self.c
        