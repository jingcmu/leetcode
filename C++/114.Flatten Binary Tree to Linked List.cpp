/*
���������Ҳ����ԭ���㷨�����ǿռ���O(log n)
��������㷨�ã�help����ֵ����������һ���ڵ�
Ϊʲô��
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
        cur->left = NULL; //��ָ��һ����Ϊnull
        if(left) {
            cur->right = left; //��ָ����ָ������
            cur = help(left);  //��������˳�����ص������ӵ����һ���ڵ�
        }
        if(right) {
            cur->right = right;//��ָ����ָ���Һ���
            cur = help(right); //�ٰ��Һ�����˳�����ص����Һ��ӵ����һ���ڵ�
        }
        return cur;
    }
};


//�����������ԭ���㷨����Ϊ�ռ�����O(n+log(n))��
//ԭ���㷨�ǿռ�ֻ��O(1)
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