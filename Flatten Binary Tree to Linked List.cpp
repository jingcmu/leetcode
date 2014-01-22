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
private:
    vector<TreeNode *> v;
public:
    void helper(TreeNode *root){
        if(!root){
            return;
        }
        v.push_back(root);
        if(root->left){
            helper(root->left);
            root->left = NULL;
        }
        if(root->right){
            helper(root->right);
            root->right = NULL;
        }
    }
    void flatten(TreeNode *root) {
        if(!root) return;
        }
        v.clear();
        helper(root);
        int len = v.size();
        for(int i=1; i<len; i++){
            v[i-1]->right = v[i];
        }
    }
};