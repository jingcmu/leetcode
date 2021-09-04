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
    int pathSum(TreeNode* root, int targetSum, bool counting = false) {
        int n = 0;
        
        if(root == nullptr) {
            return 0;
        }
        
        if(counting == false) {
            n += pathSum(root->left, targetSum, false);
            n += pathSum(root->right, targetSum, false);
        }
        
        targetSum -= root->val;
        if(targetSum == 0) {
            n++;
        }
        
        n += pathSum(root->left, targetSum, true);
        n += pathSum(root->right, targetSum, true);
        return n;
    }
};