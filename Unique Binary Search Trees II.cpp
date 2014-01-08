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
public:
    vector<TreeNode *> generateTrees(int begin, int end){
        vector<TreeNode *> ret;
        if(begin>end){
            ret.push_back(NULL);
            return ret;
        }
        for(int i=begin; i<=end; i++){
            vector<TreeNode *> left = generateTrees(begin, i-1);
            vector<TreeNode *> right = generateTrees(i+1, end);
            for(int j=0; j<left.size(); j++){
                for(int k=0; k<right.size(); k++){
                    TreeNode *Node = new TreeNode(i);
                    Node->left = left[j];
                    Node->right = right[k];
                    ret.push_back(Node);
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return generateTrees(1,n);
    }
};