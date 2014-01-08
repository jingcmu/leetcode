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
    bool hasPathSum(TreeNode *root, int sum, int sumToNow, bool &equal) {
        if(!root){
            return false;
        }
        sumToNow += root->val;
        if(!root->right && !root->left){
            if(sumToNow == sum){
                equal = true;
                return true;
            }
            else{
                return false;
            }
        }
        if(hasPathSum(root->right, sum, sumToNow, equal)||hasPathSum(root->left, sum, sumToNow, equal)){
            equal = true;
            return true;
        }
        else{
            return false;
        }
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sumToNow = 0;
        bool equal = false;
        hasPathSum(root, sum, sumToNow, equal);
        return equal;
    }
};