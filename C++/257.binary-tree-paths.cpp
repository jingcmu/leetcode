/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root != nullptr) {
            binaryTreePaths(root, "");
        }
        
        return v_str;
    }
    
private:
    vector<string> v_str;
    void binaryTreePaths(TreeNode* node, string s) {
        s == ""? s += to_string(node->val) : s += "->" + to_string(node->val);
        if (node->left != nullptr) {
            binaryTreePaths(node->left, s);
        }
        if (node->right != nullptr) {
            binaryTreePaths(node->right, s);
        } 
        if (node->right == nullptr && node->left == nullptr) {
            v_str.push_back(s);
        }
    }
};