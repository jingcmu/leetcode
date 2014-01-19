/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//思路：用vector模拟queue操作，把每一层的连起来即可
class Solution {
public:
    void levelOrder(TreeLinkNode *root) {
        vector<TreeLinkNode*> tree; //用vector模拟队列操作
        int head = 0, tail = 0;
        if(root){ //如果root不是空，先push进去
            tree.push_back(root);
            tail++;
        }
        while(head!=tail){
            int tail_current = tail; //记录下当前的tail位置，从head到tail_current是一层
            for(; head<tail_current; head++){
                if(tree[head]->left){ //先左
                    tree.push_back(tree[head]->left);
                    tail++;
                }
                if(tree[head]->right){ //后右
                    tree.push_back(tree[head]->right);
                    tail++;
                }
            }
			//把刚才push进去的节点连起来
            for(int i=head; i<tail-1; i++){
                tree[i]->next = tree[i+1];
            }
        }
    }

    void connect(TreeLinkNode *root) {
        levelOrder(root);
    }
};

