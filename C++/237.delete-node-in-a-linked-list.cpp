/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *last = node;
        while(node->next != nullptr) {
            node->val = node->next->val;
            last = node;
            node = node->next;            
        }
        last->next = nullptr;
    }
};