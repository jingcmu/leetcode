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
������Ľڵ�ŵ�vector�У�Ȼ���vector���в���
ÿ�ΰ��м�ĵ��ó�������TreeNode��Ȼ�������������еݹ�
*/
class Solution {
public:
    TreeNode *helper(int left, int right, vector<int> &v){
        if(left>right){
            return NULL;
        }
        int middle = (left+right)>>1; //�м�ڵ�����
        TreeNode *node = new TreeNode(v[middle]); //���м�ڵ㹹��TreeNode
        node->left = helper(left,middle-1, v);
        node->right = helper(middle+1,right, v);
        return node;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> v;
		//�Ȱ�ListNode���ŵ�vector��
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