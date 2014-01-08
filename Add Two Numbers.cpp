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
    int add(int a, int b, int *carry){
        int res = a+b+*carry;
        if(res >= 10){
            *carry = 1;
            return res%10;
        }
        else{
            *carry = 0;
            return res;
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int carry = 0;
        ListNode *ll1 = l1, *ll2 = l2, *last;
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        while(l1 && l2){
            l2->val = l1->val = add(l1->val, l2->val, &carry);
            last = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *remain = l2?l2:l1, *res = l2?ll2:ll1;
        while(remain){
            remain->val = add(remain->val, 0, &carry);
            last = remain;
            remain = remain->next;
        }
        if(carry){
            last->next = new ListNode(1);
        }
        return res;
    }
};