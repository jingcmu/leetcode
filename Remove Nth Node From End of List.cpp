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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *remove = head;
        ListNode *current = head;
        for(int i=0; i<n; i++){
            current = current->next;
        }
        if(!current){
            head = head->next;
            return head;
        }
        while(current->next){
            current = current->next;
            remove = remove->next;
        }
        remove->next = remove->next->next;
        return head;
    }
};