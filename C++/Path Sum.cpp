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
用DFS和BFS都行吧，不过因为不是求最短XX，所以深搜就行了，深搜也好写一点
终止条件：1、传进来的指针为NULL 2、无子节点，且到当前节点的和不等于目标
完成条件：无子节点且到当前节点的和等于目标
*/
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum, int sumToNow) {
        if(!root) return false; //终止条件
        sumToNow += root->val;  //得到到当前节点的和
        if(!root->right && !root->left) { //无子节点
            if(sumToNow == sum) return true; //完成条件
            else return false;	//终止条件
        }
        if(hasPathSum(root->right, sum, sumToNow) || //分别对左右子节点递归
			hasPathSum(root->left, sum, sumToNow)) return true;
        else return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        int sumToNow = 0;
        return hasPathSum(root, sum, sumToNow);
    }
};

Second Try:
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == nullptr) return false;
        return helper(root, sum, 0);
    }
private: 
    bool helper(TreeNode *node, int sum, int curSum) {
        if(node == nullptr) {
            return false;
        }
        if(node->right == node->left && curSum + node->val == sum) {
            return true;
        }
        return helper(node->right, sum, curSum + node->val) ||
                helper(node->left, sum, curSum + node->val);
    }
};