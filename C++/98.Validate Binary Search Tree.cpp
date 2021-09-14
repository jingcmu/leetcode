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
��һ�ֽⷨ����Tree�����������������ŵ�vector��Ȼ���ж�vector�ǲ�������
*/
class Solution {
private:
    vector<int> v;
public:
	//�������
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
����һЩ�ķ�����ע��ݹ�Ĳ�����lower��upper�������쳣����
���ڵ��ֵ��Ϊlower����ȥ���ᱻ����������ÿ���ڵ�ȽϵĶ���
�����ڵ��ֵ��Ϊupper����ȥ���ᵱ��������ÿ���ڵ�ȽϵĶ���
��֮ǰ���Ĵ�������ӽڵ����ֱ�Ӹ��ڵ�Ƚϣ��ǾͲ�����BST�Ķ�����
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