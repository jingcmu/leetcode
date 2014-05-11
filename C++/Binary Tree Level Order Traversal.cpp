/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q, q_r;
        vector<vector<int>> v_res;
        vector<int> v;
        if(root == nullptr) return v_res;
        q.push(root);
        while(!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            v.push_back(t->val);
            if(t->left) q_r.push(t->left);
            if(t->right) q_r.push(t->right);
            if(q.empty()) {
                v_res.push_back(v);
                v.clear();
                swap(q, q_r);
            }
        }
        return v_res;
    }
};