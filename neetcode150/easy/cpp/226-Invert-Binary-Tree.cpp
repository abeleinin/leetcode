// Definition for a binary tree node.
#include <cstddef>

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
    void swap(TreeNode* t) {
        auto temp = t->left;
        t->left = t->right;
        t->right = temp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        swap(root);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};