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
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool check = dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;

        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);
        if ((((root->val == p->val) || (root->val == q->val)) && l) || (((root->val == p->val) || (root->val == q->val)) && r) || (l && r)) {
            ans = root;
        }

        return ((root->val == p->val) || (root->val == q->val)) || l || r;
    }
};
