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
����DFS���ݹ��ʱ�򣬴���ȥ��ǰ�ڵ��ֵ
*/
class Solution {
public:
    int sumNumbers(TreeNode *tree, int number){
        int sum = number*10, left=0, right=0;
        sum += tree->val; //�õ���ǰ�ڵ��ֵ
        if(tree->left) { //�����߲�Ϊ�գ��ݹ����������
            left = sumNumbers(tree->left, sum);
        }
        if(tree->right) {//����ұ߲�Ϊ�գ��ݹ����������
            right = sumNumbers(tree->right, sum);
        }
        if(!left && !right) { //������Ҷ�Ϊ�գ����ص�ǰ�ڵ��ֵ
            return sum;
        }
        else {
            return left+right; //���򣬷������ߵĺ�
        }
    }
    int sumNumbers(TreeNode *root) {
        if(root == NULL) return 0;
        return sumNumbers(root, 0);
    }
};

Second try:
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
    int sum = 0;
public:
    void helper(TreeNode *root, int num) {
        if(!root) return;
        if(root->left) {
            helper(root->left, (num+root->val)*10);
        }
        if(root->right) {
            helper(root->right, (num+root->val)*10);
        }
        if(root->left == NULL && root->right == NULL) {
            sum += (num+root->val);
        }
    }
    int sumNumbers(TreeNode *root) {
        helper(root, 0);
        return sum;
    }
};