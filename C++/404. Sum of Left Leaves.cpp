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
private:
    void sumOfLeftLeaves(TreeNode* root, bool is_left, int& sum) {
        if (root == nullptr) {
            return;
        }

        if (is_left && root->left == nullptr && root->right == nullptr) {
            sum += root->val;
        }            

        sumOfLeftLeaves(root->left, true, sum);
        sumOfLeftLeaves(root->right, false, sum);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == nullptr) {
            return sum;
        }
        sumOfLeftLeaves(root->left, true, sum);
        sumOfLeftLeaves(root->right, false, sum);
        return sum;
    }
};