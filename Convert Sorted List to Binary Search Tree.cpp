/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    vector<int> v;
public:
    TreeNode *helper(int left, int right){
        if(left>right){
            return NULL;
        }
        int middle = (left+right)>>1;
        TreeNode *node = new TreeNode(v[middle]);
        node->left = helper(left,middle-1);
        node->right = helper(middle+1,right);
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        v.clear();
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int len = v.size();
        if(!len){
            return NULL;
        }
        return helper(0, len-1);
    }
};
