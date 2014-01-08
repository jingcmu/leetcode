/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void levelOrder(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<TreeLinkNode*> tree;
        int head = 0, tail = 0;
        if(root){
            tree.push_back(root);
            tail++;
        }
        while(head!=tail){
            int tail_current = tail;
            for(; head<tail_current; head++){
                if(tree[head]->left){
                    tree.push_back(tree[head]->left);
                    tail++;
                }
                if(tree[head]->right){
                    tree.push_back(tree[head]->right);
                    tail++;
                }
            }
            for(int i=head; i<tail-1; i++){
                tree[i]->next = tree[i+1];
            }
        }
    }


    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        levelOrder(root);
    }
};

