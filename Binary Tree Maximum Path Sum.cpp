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
    int maxPathSum(TreeNode *root) {  
        int res = INT_MIN;  
        maxPathSumRe(root, res);  
        return res;  
    }  
  
    int maxPathSumRe(TreeNode *node, int &res)  
    {  
        if (!node) return 0;  
        int l = maxPathSumRe(node->left, res);  //返回左边单线最大值
        int r = maxPathSumRe(node->right, res); //返回右边单线最大值
        int sum = max(node->val, max(l, r) + node->val);  //以当前节点为终点的最大可能值
        res = max(res, sum);    //用单线最大值试试
        res = max(res, l + r + node->val);    //用双线最大值试试
        return sum;  
    }  
};