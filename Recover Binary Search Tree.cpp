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
    TreeNode *s1,*s2,*pre; 
    void inorder(TreeNode *root) 
    { 
        if(!root){
            return;
        }
        inorder(root->left); 
        if(pre && pre->val > root->val) 
        { 
			//tricky here
            if(s1 == NULL){  //the first wrong node is a larger one
                s1 = pre;    //the second wrong node is a smaller one
                s2 = root;
            }
            else s2 = root; 
        } 
        pre = root; 
        inorder(root->right); 
    } 
    void recoverTree(TreeNode *root) { 
        if(!root){
            return;
        }
        s1 = s2 = pre = NULL; 
        inorder(root); 
        swap(s1->val,s2->val); 
    } 
};  
