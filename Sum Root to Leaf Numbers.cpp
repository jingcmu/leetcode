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
    int sumNumbers(TreeNode *tree, int number){
        int sum = number*10, left=0, right=0;
        sum += tree->val;
        if(tree->left){
            left = sumNumbers(tree->left, sum);
        }
        if(tree->right){
            right = sumNumbers(tree->right, sum);
        }
        if(!left && !right){
            return sum;
        }
        else{
            return left+right;
        }
    }
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL){
            return 0;
        }
        return sumNumbers(root, 0);
    }
};