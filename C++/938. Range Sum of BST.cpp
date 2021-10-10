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
    Solution() {
        sum = 0;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        
        if (root->val <= high && root->val >= low) {
            sum += root->val;
            rangeSumBST(root->right, low, high);
            rangeSumBST(root->left, low, high);
        } else if (root->val > high) {
            rangeSumBST(root->left, low, high);
        } else {
            rangeSumBST(root->right, low, high);
        }
        
        return sum;
    }

private:
    int sum;
};