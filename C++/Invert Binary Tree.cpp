class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        auto q = queue<TreeNode*>();
        q.push(root);
        while(!q.empty()) {
            auto n = q.front(); q.pop();
            swap(n->left, n->right);
            if (n->left != nullptr) {
                q.push(n->left);
            }
            if (n->right != nullptr) {
                q.push(n->right);
            }
        }
        return root;
    }
};