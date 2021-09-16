First Try:
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//�ݹ�ⷨ
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
//�ǵݹ�ⷨ-ʹ�ö���
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
            for(int i=1; i<size; i++) { //��ѭ���������һ��ڵ�
                ptr_r = q.front(); q.pop();
                if(ptr_r->left) q.push(ptr_r->left);
                if(ptr_r->right) q.push(ptr_r->right);
                ptr_l->next = ptr_r; //���ӽڵ�
                ptr_l = ptr_r; //ָ������
            }
        }
    }
};