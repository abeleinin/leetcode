#include <algorithm>

using namespace std;

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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(height(root->right), height(root->left)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else if (abs(height(root->right) - height(root->left)) > 1) {
            return false;
        } else {
            return isBalanced(root->right) && isBalanced(root->left);
        }
    }
};