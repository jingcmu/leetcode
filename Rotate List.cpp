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
   ListNode *rotateRight(ListNode *head, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *ptr1, *ptr2, *res;
        int i, len;
        ptr1 = ptr2 = head;
        if(!head){
            return NULL;
        }
        if(!k){
            return head;
        }
        for(i=0; i<k; i++){
            ptr1 = ptr1->next;
            if(!ptr1){
				i++;
                break;
            }
        }
        if(i<k || (i==k && ptr1==NULL)){
            len = i; 
            k = k%len;
            if(!k){
                return head;
            }
            ptr1 = head;
            for(i=0; i<k; i++){
                ptr1 = ptr1->next;
            }
        }
        while(ptr1->next){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        res = ptr2->next;
        ptr2->next = NULL;
        ptr1->next = head;
        return res;
    }
};