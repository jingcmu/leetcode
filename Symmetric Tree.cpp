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
   bool isSymmetric(TreeNode *left, TreeNode *right){
       if(left == NULL && right == NULL){   // empty trees are symmetric 
           return true;
       }
       else if(left == NULL || right == NULL){  // empty and non-empty trees are non-symmetric 
           return false;
       }
	   //judge whether left->left right->right, left->right, right->left are symmetric
       return (left->val == right->val)&&isSymmetric(left->left, right->right)&&isSymmetric(left->right, right->left);
   }
   bool isSymmetric(TreeNode *root) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       if(root == NULL){    // empty tree is symmetric
           return true;
       }
       return isSymmetric(root->left, root->right);  // whether left and right sub-tree are symmetric
   }
};