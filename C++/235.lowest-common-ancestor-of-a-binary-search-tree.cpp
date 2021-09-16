/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if(p->val > q->val) {
            return lowestCommonAncestor(root, q, p);
        }
        if(root->val >= p->val && root->val <= q->val) {
            return root;
        } else if(root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if(root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return nullptr;
    }
};