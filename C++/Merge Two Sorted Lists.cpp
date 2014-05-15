Third Try:
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
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode head(-1), *ptr;
        if(l1->val <= l2->val) {
            head.next = l1;
            l1 = l1->next;
        }
        else {
            head.next = l2;
            l2 = l2->next;
        }
        ptr = head.next;
        while(l1 || l2) {
            if(l1 == nullptr) {
                ptr->next = l2; 
                break;
            }
            if(l2 == nullptr) {
                ptr->next = l1;
                break;
            }
            if(l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            }
            else {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
        }
        return head.next;
    }
};

First Try:
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

Second Try:
思路一样就是写得好一点,不过其实效率略低
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
        ListNode head(-1);
        for (ListNode* p = &head; l1 != nullptr || l2 != nullptr; p = p->next) {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            if (val1 <= val2) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        return head.next;
    }
};