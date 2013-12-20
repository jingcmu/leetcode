First Try:
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
public :
   int maxDepth(TreeNode * root) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       int length, length_left, length_right;
       if( root){                     //whether root is NoNULL
           length = 1;
       }
       else{
           return 0;
       }
       length_left = maxDepth( root->left);   //recursion to left tree
       length_right = maxDepth( root->right); //recursion to right tree
       length += length_right>length_left?length_right:length_left; //add the larger to length
       return length;
   }
};

Second Try:
class Solution {
public :
   int maxDepth(TreeNode * root) {
       if(root == nullptr) return 0;
       return max(maxDepth(root->left), maxDepth(root->right)) + 1;
   }
};