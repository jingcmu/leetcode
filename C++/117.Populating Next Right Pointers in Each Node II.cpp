/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//˼·����vectorģ��queue��������ÿһ�������������
class Solution {
public:
    void levelOrder(TreeLinkNode *root) {
        vector<TreeLinkNode*> tree; //��vectorģ����в���
        int head = 0, tail = 0;
        if(root){ //���root���ǿգ���push��ȥ
            tree.push_back(root);
            tail++;
        }
        while(head!=tail){
            int tail_current = tail; //��¼�µ�ǰ��tailλ�ã���head��tail_current��һ��
            for(; head<tail_current; head++){
                if(tree[head]->left){ //����
                    tree.push_back(tree[head]->left);
                    tail++;
                }
                if(tree[head]->right){ //����
                    tree.push_back(tree[head]->right);
                    tail++;
                }
            }
			//�Ѹղ�push��ȥ�Ľڵ�������
            for(int i=head; i<tail-1; i++){
                tree[i]->next = tree[i+1];
            }
        }
    }

    void connect(TreeLinkNode *root) {
        levelOrder(root);
    }
};

