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
典型的DFS，没啥好说的
*/
class Solution {
private:
    vector<vector<int> > ret;
public:
    void pathSum(TreeNode *node, int sum2now, vector<int> temp, int sum){
        if(!node) return;
        sum2now += node->val;
        temp.push_back(node->val);
        if(!node->left && !node->right){
            if(sum2now == sum){
                ret.push_back(temp);
                return;
            }
        }
        else{
            pathSum(node->left, sum2now, temp, sum);
            pathSum(node->right, sum2now, temp, sum);
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> temp;
        ret.clear();
        pathSum(root, 0, temp, sum);
        return ret;
    }
};