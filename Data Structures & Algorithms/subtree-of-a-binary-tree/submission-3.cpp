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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* check = nullptr;

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val == subRoot->val) {
                    check = node;
                    if (dfs(check, subRoot)) return true;
                }

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return false;
    }

    bool dfs(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return true;

        if (a == nullptr || b == nullptr) return false;

        if (a->val != b->val) return false;

        bool left = dfs(a->left, b->left);
        bool right = dfs(a->right, b->right);

        return left && right;
    }
};
