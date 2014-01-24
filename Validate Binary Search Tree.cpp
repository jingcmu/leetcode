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
第一种解法，对Tree进行中序遍历，结果放到vector，然后判断vector是不是升序
*/
class Solution {
private:
    vector<int> v;
public:
	//中序遍历
    void help(TreeNode *root){
        if(root->left){
            help(root->left);
        }
        v.push_back(root->val);
        if(root->right){
            help(root->right);
        }
    }
    bool isValidBST(TreeNode *root) {
        if(!root){
            return true;
        }
        v.clear();
        help(root);
        int len = v.size();
        for(int i=0; i<len-1; i++){
            if(v[i]>=v[i+1]){
                return false;
            }
        }
        return true;
    }
};

/*
更好一些的方法：注意递归的参数，lower和upper的设置异常巧妙
根节点的值作为lower传下去，会被当做右子树每个节点比较的对象
而根节点的值作为upper传下去，会当做左子树每个节点比较的对象
我之前犯的错误就是子节点跟其直接父节点比较，那就不满足BST的定义了
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    bool isValidBST(TreeNode* root, int lower, int upper) {
        if (root == nullptr) return true;
        return root->val > lower && root->val < upper
                && isValidBST(root->left, lower, root->val)
                && isValidBST(root->right, root->val, upper);
    }
};