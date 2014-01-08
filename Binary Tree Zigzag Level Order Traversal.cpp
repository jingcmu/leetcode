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
private:
    vector<vector<int> > ret;
    
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ret.clear();
        queue<TreeNode *> TreeQueue;
        TreeNode *temp;
        TreeQueue.push(root);
        int size;
        if(!root){
            return ret;
        }
        while(size = TreeQueue.size()){
            vector<int> v;
            for(int i=0; i<size; i++){
                temp = TreeQueue.front();
                TreeQueue.pop();
                v.push_back(temp->val);
                if(temp->left){
                    TreeQueue.push(temp->left);
                }
                if(temp->right){
                    TreeQueue.push(temp->right);
                }
            }
            ret.push_back(v);
        }
        for(int i=0; i<ret.size(); i++){
            if(i%2){
                reverse(ret[i].begin(), ret[i].end());
            }
        }
        return ret;
    }
};