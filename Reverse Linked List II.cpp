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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *start, *end, *beforeStart, *afterEnd, *ptr;
        start = end = beforeStart = afterEnd = NULL;
        ptr = head;
        for(int i=1; i<m; i++){
            beforeStart = ptr;
            ptr = ptr->next;
        }
        start = end = ptr;
        for(int i=m; i<=n; i++){
            afterEnd = ptr->next;
            ptr->next = end;
            end = ptr;
            ptr = afterEnd;
        }
        if(beforeStart == NULL){
            head = end;
        }
        else{
            beforeStart->next = end;
        }
        start->next = afterEnd;
        return head;
    }
};