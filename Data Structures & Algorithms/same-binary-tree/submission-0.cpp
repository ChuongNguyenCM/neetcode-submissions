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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if ((p && !q) || (q && !p)) return false;
        queue<TreeNode*> x1;
        queue<TreeNode*> x2;

        x1.push(p);
        x2.push(q);
        while (!x1.empty() && !x2.empty()) {
            int n1 = x1.size();
            int n2 = x2.size();

            if (n1 != n2) return false;
            for (int i = 0; i < n1; ++i) {
                TreeNode* node1 = x1.front();
                TreeNode* node2 = x2.front();
                x1.pop();
                x2.pop();

                if (node1->val != node2->val) return false;
                if ((node1->left && !node2->left) || (!node1->left && node2->left)) return false;
                if ((node1->right && !node2->right) || (!node1->right && node2->right)) return false;
                
                if (node1->left) x1.push(node1->left);
                if (node1->right) x1.push(node1->right);
                if (node2->left) x2.push(node2->left);
                if (node2->right) x2.push(node2->right);
            }
        }

        return true;
    }
};
