/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
��ʵ���ǰ�����ʵı��Σ���һ�����У���һ��������¼�кţ�
�����������򣬶�ż���б���ԭ����˳�򲻱�
*/
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ret;
        queue<TreeNode *> TreeQueue;
        TreeNode *temp;
        TreeQueue.push(root);
        int size;
        if(!root) return ret;
        while(size = TreeQueue.size()) { //�õ���ǰ���е�size
            vector<int> v;
			//�ѵ�ǰ����ȫ�����У����ŵ�ret�У�ͬʱpush��һ��Ľڵ�
            for(int i=0; i<size; i++){ 
                temp = TreeQueue.front();
                TreeQueue.pop();
                v.push_back(temp->val);
                if(temp->left) TreeQueue.push(temp->left);
                if(temp->right) TreeQueue.push(temp->right);
            }
            ret.push_back(v);
        }
        for(int i=0; i<ret.size(); i++){
            if(i%2){ //����������
                reverse(ret[i].begin(), ret[i].end());
            }
        }
        return ret;
    }
};