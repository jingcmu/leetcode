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
   ListNode *deleteDuplicates(ListNode *head) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       ListNode *cur1, *cur2;
       cur1 = cur2 = head;				// both points are in the begining
       while(cur1){
           while(cur1->next && cur1->val == cur1->next->val){ // if duplicate, move cur1 forward 
               cur1 = cur1->next;
           }
           cur2->next = cur1->next;      // link cur2 to next element
           cur2 = cur1 = cur1->next;     // move cur1 and cur2 forward
       }
       return head;
   }
};