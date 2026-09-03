/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int a = dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (!root) return -1;
        
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        ans = max(ans, l + r);

        return max(l, r);
    }
};
