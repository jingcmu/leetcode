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
��DFS��BFS���аɣ�������Ϊ���������XX���������Ѿ����ˣ�����Ҳ��дһ��
��ֹ������1����������ָ��ΪNULL 2�����ӽڵ㣬�ҵ���ǰ�ڵ�ĺͲ�����Ŀ��
������������ӽڵ��ҵ���ǰ�ڵ�ĺ͵���Ŀ��
*/
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum, int sumToNow) {
        if(!root) return false; //��ֹ����
        sumToNow += root->val;  //�õ�����ǰ�ڵ�ĺ�
        if(!root->right && !root->left) { //���ӽڵ�
            if(sumToNow == sum) return true; //�������
            else return false;	//��ֹ����
        }
        if(hasPathSum(root->right, sum, sumToNow) || //�ֱ�������ӽڵ�ݹ�
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