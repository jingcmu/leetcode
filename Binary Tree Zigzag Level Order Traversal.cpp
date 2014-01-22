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
其实就是按层访问的变形，用一个队列，用一个变量记录行号，
对奇数行逆序，对偶数行保留原来的顺序不变
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
        while(size = TreeQueue.size()) { //得到当前队列的size
            vector<int> v;
			//把当前队列全部出列，并放到ret中，同时push下一层的节点
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
            if(i%2){ //奇数行逆序
                reverse(ret[i].begin(), ret[i].end());
            }
        }
        return ret;
    }
};