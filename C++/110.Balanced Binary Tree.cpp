First Try:
//递归计算两边的深度，深度差不大于1才算平衡
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
    int getDepth(TreeNode *root){
        if(root == NULL)
            return 0;
        else{
            int l, r;
            l = getDepth(root->left);
            r = getDepth(root->right);
            return max(l,r)+1; 
        }
    }
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL)
            return true;
        int diff = getDepth(root->left) - getDepth(root->right);
        if(diff > 1  || diff < -1)
            return false;
        if(!isBalanced(root->left) || !isBalanced(root->right))
            return false;
        return true;
    }
};

//Second Try:
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == nullptr) return true;
        if(abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
        return isBalanced(root->right) && isBalanced(root->left);
    }
private:
    int getHeight(TreeNode *root) {
        if(root == nullptr) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};