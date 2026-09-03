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
    int best;

    int maxPathSum(TreeNode* root) {
        best = INT_MIN;
        dfs(root);
        return best;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int L = max(0, dfs(node->left));   // gain from left child
        int R = max(0, dfs(node->right));  // gain from right child

        // path passing through this node (could take both sides)
        best = max(best, node->val + L + R);

        // return max gain to parent (can only take one side)
        return node->val + max(L, R);
    }
};
