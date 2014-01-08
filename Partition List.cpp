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
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *smaller, *biger, *smaller_c, *biger_c;
        smaller = biger = smaller_c = biger_c = NULL;
        while(head){
            if(head->val < x){
                if(!smaller) smaller = smaller_c = head;
                else{
                    smaller_c->next = head;
                    smaller_c = smaller_c->next;
                } 
            }
            else{
                if(!biger) biger = biger_c = head;
                else{
                    biger_c->next = head;
                    biger_c = biger_c->next;
                } 
            }
            head = head->next;
        }
        if(!smaller && !biger) return NULL;
        if(biger) biger_c->next = NULL;
        if(smaller){
            smaller_c->next = NULL;
            smaller_c->next = biger;
            return smaller;
        }
        return biger;
    }
};