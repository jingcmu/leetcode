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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *cur, *head;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val > l2->val){
            head = l2;
            l2 = l2->next;
        }
        else{
            head = l1;
            l1 = l1->next;
        }
        cur = head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur -> next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;
        return head;
    }
};
