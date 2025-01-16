#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        } else if (t1 == NULL || t2 == NULL || t1->val != t2->val) {
            return false;
        } else {
            return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) {
            return true;
        }
        if (root == NULL || subRoot == NULL) {
            return false;
        }
        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot) || isSameTree(root, subRoot);
    }
};