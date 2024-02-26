from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def visit(self, node, lv, max_lv, res):
        if node is None:
            return res
        
        if max_lv[0] < lv:
            res.append(node.val)
            max_lv[0] = lv

        self.visit(node.right, lv+1, max_lv, res)
        self.visit(node.left, lv+1, max_lv, res)
        return res
        
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        max_lv = [0]
        return self.visit(root, 1, max_lv, [])