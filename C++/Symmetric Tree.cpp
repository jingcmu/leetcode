First Try:
µÝ¹é°æ
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

Second Try:
µü´ú°æ
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
    bool isSymmetric(TreeNode *root) {
        if(root == nullptr) return true;
        stack<TreeNode *> s;
        s.push(root->right); 
        s.push(root->left);
        while(!s.empty()) {
            TreeNode *p = s.top(); s.pop();
            TreeNode *q = s.top(); s.pop();
            if(p == nullptr && q == nullptr) continue;
            if(p == nullptr || q == nullptr) return false;
            if(p->val != q->val) return false;
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
};