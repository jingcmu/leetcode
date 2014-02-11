/*
理论上这个也不是原地算法，但是空间是O(log n)
比下面的算法好，help返回值是链表的最后一个节点
为什么？
*/
class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root) return;
        else help(root);
    }
    
    TreeNode * help(TreeNode *cur) {
        if(!cur) return NULL;
        if(cur->right == NULL && cur->left == NULL) return cur;
        TreeNode *left = cur->left;
        TreeNode *right = cur->right;
        cur->left = NULL; //左指针一律置为null
        if(left) {
            cur->right = left; //右指针先指向左孩子
            cur = help(left);  //把左孩子捋顺，返回的是左孩子的最后一个节点
        }
        if(right) {
            cur->right = right;//右指针再指向右孩子
            cur = help(right); //再把右孩子捋顺，返回的是右孩子的最后一个节点
        }
        return cur;
    }
};


//下面这个不是原地算法，因为空间用了O(n+log(n))，
//原地算法是空间只用O(1)
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
private:
    vector<TreeNode *> v;
public:
    void helper(TreeNode *root){
        if(!root){
            return;
        }
        v.push_back(root);
        if(root->left){
            helper(root->left);
            root->left = NULL;
        }
        if(root->right){
            helper(root->right);
            root->right = NULL;
        }
    }
    void flatten(TreeNode *root) {
        if(!root) return;
        }
        v.clear();
        helper(root);
        int len = v.size();
        for(int i=1; i<len; i++){
            v[i-1]->right = v[i];
        }
    }
};