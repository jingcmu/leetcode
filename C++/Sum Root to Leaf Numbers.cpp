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
采用DFS，递归的时候，传下去当前节点的值
*/
class Solution {
public:
    int sumNumbers(TreeNode *tree, int number){
        int sum = number*10, left=0, right=0;
        sum += tree->val; //得到当前节点的值
        if(tree->left) { //如果左边不为空，递归求解左子树
            left = sumNumbers(tree->left, sum);
        }
        if(tree->right) {//如果右边不为空，递归求解右子树
            right = sumNumbers(tree->right, sum);
        }
        if(!left && !right) { //如果左右都为空，返回当前节点的值
            return sum;
        }
        else {
            return left+right; //否则，返回两边的和
        }
    }
    int sumNumbers(TreeNode *root) {
        if(root == NULL) return 0;
        return sumNumbers(root, 0);
    }
};