/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public :
    ListNode * swap(ListNode *left, ListNode *mid, ListNode *right){
        if(!right){
            return mid;
        }
        mid->next = right->next;
        right->next = mid;
        if(left) left->next = right;
        if(mid->next){
            swap(mid, mid->next, mid->next->next);
        }
        return right;
    }

    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *left, *right;
        if(! head || ! head->next){
            return head;
        }
        return swap( NULL, head, head->next);
    }
};
