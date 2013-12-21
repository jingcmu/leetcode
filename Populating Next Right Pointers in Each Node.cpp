First Try:
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//递归解法
class Solution {
public:
    void connect(TreeLinkNode *left, TreeLinkNode *right) {
        if(left == NULL) return;
        left->next = right;
        connect(left->left, left->right);
        connect(left->right, right->left);
        connect(right->left, right->right);
    }
    
    void connect(TreeLinkNode *root) {
        if(root == NULL || root->right == NULL) return;
        connect(root->left, root->right);
    }
};

Second Try:
//非递归解法-使用队列
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeLinkNode *ptr_l, *ptr_r;
            int size = q.size();
            ptr_l = q.front(); q.pop();
            if(ptr_l->left) q.push(ptr_l->left);
            if(ptr_l->right) q.push(ptr_l->right);
            for(int i=1; i<size; i++) { //在循环中清掉上一层节点
                ptr_r = q.front(); q.pop();
                if(ptr_r->left) q.push(ptr_r->left);
                if(ptr_r->right) q.push(ptr_r->right);
                ptr_l->next = ptr_r; //连接节点
                ptr_l = ptr_r; //指针右移
            }
        }
    }
};