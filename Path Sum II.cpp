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
    int sum;
public:
    void pathSum(TreeNode *node, int sum2now, vector<int> temp){
        if(!node){
            return;
        }
        sum2now += node->val;
        temp.push_back(node->val);
        if(!node->left && !node->right){
            if(sum2now == this->sum){
                ret.push_back(temp);
                return;
            }
        }
        else{
            pathSum(node->left, sum2now, temp);
            pathSum(node->right, sum2now, temp);
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> temp;
        ret.clear();
        this->sum = sum;
        pathSum(root, 0, temp);
        return ret;
    }
};