2015/5/14
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l3(-1);
        ListNode* ptr = &l3;
        int carry = 0;
        while (l1 || l2) {
            int left = 0, right = 0;
            if (l1 != nullptr) {
                left = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                right = l2->val;
                l2 = l2->next;
            }
            ptr->next = new ListNode((left + right + carry) % 10);
            carry = (left + right + carry) / 10;
            ptr = ptr->next;
        }
        if (carry) {
            ptr->next = new ListNode(1);
        }
        return l3.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 思路：考察基本的链表操作，一种不太好的做法是另外分配一个空间放结果，
 我决定不使用额外空间， 所以第一次写了70多行代码才AC，
 后来经过改进，就变成了下面的40多行代码
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

Second Try:
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode res(-1);
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        int carry = 0;
        ListNode *ptr = &res;
        while(l1 || l2) {
            if(l1 == nullptr) {
                if(carry == 0) {
                    ptr->next = l2;
                    break;
                }
                else {
                    ptr->next = new ListNode((l2->val+carry)%10);
                    carry = (l2->val+carry)/10;
                    ptr = ptr->next;
                    l2 = l2->next;
                    continue;
                }
            }
            if(l2 == nullptr) {
                if(carry == 0) {
                    ptr->next = l1;
                    break;
                }
                else {
                    ptr->next = new ListNode((l1->val+carry)%10);
                    carry = (l1->val+carry)/10;
                    ptr = ptr->next;
                    l1 = l1->next;
                    continue;
                }
            }
            ptr->next = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            ptr = ptr->next;
            l2 = l2->next;
            l1 = l1->next;
        }
        if(carry) {
            ptr->next = new ListNode(1);
        }
        return res.next;
    }
};
