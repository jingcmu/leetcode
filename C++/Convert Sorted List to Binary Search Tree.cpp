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
/*
把链表的节点放到vector中，然后对vector进行操作
每次把中间的点拿出来生成TreeNode，然后对两段链表进行递归
*/
class Solution {
public:
    TreeNode *helper(int left, int right, vector<int> &v){
        if(left>right){
            return NULL;
        }
        int middle = (left+right)>>1; //中间节点坐标
        TreeNode *node = new TreeNode(v[middle]); //用中间节点构造TreeNode
        node->left = helper(left,middle-1, v);
        node->right = helper(middle+1,right, v);
        return node;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> v;
		//先把ListNode都放到vector中
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        int len = v.size();
        if(!len){
            return NULL;
        }
        return helper(0, len-1, v);
    }
};