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
    int val = 0;

    int dfs(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        val = max(val, right + left + 2);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return val;
    }
};