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
    TreeNode *sortedArrayToBST(vector<int> &num, int l, int r){
        TreeNode *root;
        int mid = l+(r-l)/2;
        if(l>r){
            return NULL;
        }
        root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, l, mid-1);
        root->right = sortedArrayToBST(num, mid+1, r);
        return root;
    }
   
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};
