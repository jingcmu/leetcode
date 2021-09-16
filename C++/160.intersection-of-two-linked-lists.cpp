class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;
        while (pA) {
            lenA++;
            pA = pA->next;
        }
        while (pB) {
            lenB++;
            pB = pB->next;
        }
        pA = headA;
        pB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                pA = pA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                pB = pB->next;
            }
        }
        while (pA) {
            if (pA == pB) {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB) {
            if (ptrA == nullptr) {
                ptrA = headB;
            }
            else {
                ptrA = ptrA->next;
            }
            if (ptrB == nullptr) {
                ptrB = headA;
            }
            else {
                ptrB = ptrB->next;
            }
        }
        return ptrA;
    }
};