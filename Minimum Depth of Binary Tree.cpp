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
    int minDepth(TreeNode *root, int depth) {
        int l_depth, r_depth;
        if(!root->left && !root->right){
            return depth;
        }
        if(root->left && root->right){
            l_depth = minDepth(root->left,depth+1);
            r_depth = minDepth(root->right,depth+1);
            return l_depth>r_depth?r_depth:l_depth;
        }
        else if(root->left){
            return minDepth(root->left,depth+1);
        }
        else if(root->right){
            return minDepth(root->right,depth+1);
        }
    }
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL){
            return 0;
        }
        return minDepth(root, 1);
    }
};