First Try:  非递归，用栈实现
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //先序遍历只需要一个栈
 //先访问当前节点，然后把当前节点入栈
 //接着访问左节点并入栈直到再无左节点
 //出栈开始对右节点的访问，这个流程要烂熟于心
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        v.clear();
        while(root || !s.empty()){
            while(root){
                v.push_back(root->val); 
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return v;
    }
};

Second Try：
class Solution {
public:
	void preorderTraversal(TreeNode *root, vector<int> &v) {
		v.push_back(root->val);
		if(root->left != nullptr) preorderTraversal(root->left, v);
		if(root->right != nullptr) preorderTraversal(root->right, v);
	}

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        v.clear();
		if(root == nullptr) return v;
        preorderTraversal(root, v);
        return v;
    }
};