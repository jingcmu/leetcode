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
        if(l>r) return NULL£»
        root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, l, mid-1);
        root->right = sortedArrayToBST(num, mid+1, r);
        return root;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
private:
    TreeNode* sortedArrayToBST(vector<int> &num, int left, int right) {
        TreeNode* root;
        int mid = (left+right)/2;
        if(left > right) return nullptr;
        root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, left, mid-1);
        root->right = sortedArrayToBST(num, mid+1, right);
        return root;
    }
};