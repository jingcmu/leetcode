/**
*思路：
*很简单的递归，这是最基本的面试题，不过要在5分钟之内搞定且一次通过要比较熟练才行。
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
   int maxDepth(TreeNode *root) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       int length, length_left, length_right;
       if(root){                     //首先要判断root是否为空
           length = 1;
       }
       else{
           return 0;
       }
       if(root->right){              //判断左子树是否为空
           length_right = maxDepth(root->right); //对左子树递归
       }
       else{
           length_right = 0;
       }
       if(root->left){               //判断右子树是否为空           length_left = maxDepth(root->left);  //对右子树递归
       }
       else{
           length_left = 0;
       }
       length += length_right>length_left?length_right:length_left; //加上左右子树中较大的
       return length;
   }
};
