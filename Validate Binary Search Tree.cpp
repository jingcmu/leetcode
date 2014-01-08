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
    vector<int> v;
public:
    void help(TreeNode *root){
        if(root->left){
            help(root->left);
        }
        v.push_back(root->val);
        if(root->right){
            help(root->right);
        }
    }
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!root){
            return true;
        }
        v.clear();
        help(root);
        int len = v.size();
        for(int i=0; i<len-1; i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};