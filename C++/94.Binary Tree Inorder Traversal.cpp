First Try��
�ݹ飬ֻʹ��һ������
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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        if(root == NULL){
            return v;
        }
        if(root->left){
            vector<int> v_t;
            v_t = inorderTraversal(root->left);
            v.insert(v.end(), v_t.begin(), v_t.end());
        }
        v.push_back(root->val);
        if(root->right){
            vector<int> v_t;
            v_t = inorderTraversal(root->right);
            v.insert(v.end(), v_t.begin(), v_t.end());
        }
        return v;
    }
};

Second Try��
�ݹ�, ��������
class Solution {
public:
    void inorderTraversal(TreeNode *root, vector<int> &v) {
        if(root->left) inorderTraversal(root->left, v);
        v.push_back(root->val);
        if(root->right) inorderTraversal(root->right, v);
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        if(root == NULL){
            return v;
        }
        inorderTraversal(root, v);
        return v;
    }
};

Thrid Try:
�ǵݹ飬ջ
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> res;
        TreeNode *p = root;
		//ֻҪ�������ǿգ��Ͱ�������ѹջ������ͷ��ʸýڵ㲢�鿴��������
        while(p != nullptr || !s.empty()) {
            if(p != nullptr) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top(); s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};

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
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return res_;
        }
        inorderTraversal(root->left);
        res_.push_back(root->val);
        inorderTraversal(root->right);
        return res_;
    }
private:
    vector<int> res_;
};
