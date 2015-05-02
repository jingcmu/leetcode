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
		TreeNode *p = root;
        while(p != nullptr || !s.empty()){
            if(p != nullptr){
                v.push_back(p->val); 
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                p = p->right;
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

Third Try:
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode *p;
        stack<const TreeNode *> s;
        p = root;
        if (p != nullptr) s.push(p);
        while (!s.empty()) {
            p = s.top();
            s.pop();
            result.push_back(p->val);
            if (p->right != nullptr) s.push(p->right);
            if (p->left != nullptr) s.push(p->left);
        }
        return result;
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
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return res_;
        }
        res_.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res_;
    }
private:
    vector<int> res_;
};