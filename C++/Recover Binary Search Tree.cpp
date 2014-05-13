/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

/*
O(n) 空间的解法是，开一个指针数组，中序遍历，将节点指针依次存放到数组里，然后寻找两
处逆向的位置，先从前往后找第一个逆序的位置，然后从后往前找第二个逆序的位置，交换这两个
指针的值。
*/

/*
O(log n) 空间的解法如下：
用递归中序遍历，中序遍历的特点是元素访问是按照从小到大被访问的，如果碰到一个逆序的，
则这个逆序的两个点有一个肯定是错了的，那么到底是哪个呢？
从中序遍历的特点可知，第一个错误的节点肯定是逆序对中的较大的，第二个则是逆序对中较小的
*/
class Solution { 
public : 
    TreeNode *first, *second, *pre; 
    void inorder(TreeNode *root) {  
        if(root->left) inorder(root->left);
        if(pre == NULL) pre = root;
        else if(pre->val > root->val) {
            if(first == NULL)   //如果first还没被赋值，则将大的那个赋给first
                first = pre;    
            second = root; //如果first已经赋值过了，则将小的那个赋给second
        } 
        pre = root; 
        if(root->right) inorder(root->right); 
    } 
    void recoverTree(TreeNode *root) { 
        if(!root) return;
        first = second = pre = NULL; 
        inorder(root);
        swap(first->val, second->val); //交换两个错误节点
    }
};  

/*
O(1) 空间的解法：Morris 中序遍历
*/

Second Try:
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
    void recoverTree(TreeNode *root) {
        if(root == nullptr) return;
        first = second = pre = nullptr;
        inorder(root);
        swap(first->val, second->val);
    }
private:
    TreeNode *first, *second, *pre;
    void inorder(TreeNode *root) {
        if(root->left) inorder(root->left);
        if(pre != nullptr) {
            if(pre->val > root->val) {
                if(first == nullptr) {
                    first = pre;
                }
                second = root;
            }
        }
        pre = root;
        if(root->right) inorder(root->right);
    }
};