/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：DFS+归并
DFS复杂度是O(log n)
归并是O(n)
*/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int size = 0;
        ListNode *ptr = head;
        //get the size of this list
        while(ptr) {
            size++;
            ptr = ptr->next;
        }
        
        //if the list contains only 0 or 1 node, then return the list
        if(size <= 1) {
            return head;
        }
        //分拆链表
        int half_size = size>>1;
        ListNode *ptr1 = head, *ptr2;
        for(int i=0; i<half_size; i++) {
			ptr2 = ptr1->next;
			if(i < half_size-1) ptr1 = ptr1->next;
        }
        ptr1->next = NULL;
        ptr1 = head;
        
		//对左右两个子链表排序
        ptr1 = sortList(ptr1);
        ptr2 = sortList(ptr2);
        
		//归并两个已经排好序的链表
        ptr = NULL;
        while(ptr1 && ptr2) {
            if(ptr1->val < ptr2->val){
                if(!ptr) {
                    head = ptr = ptr1;
                    ptr1 = ptr1->next;
                }
                else {
                    ptr->next = ptr1;
                    ptr = ptr->next;
                    ptr1 = ptr1->next;
                }
            }
            else {
                if(!ptr){
                    head = ptr = ptr2;
                    ptr2 = ptr2->next;
                }
                else{
                    ptr->next = ptr2;
                    ptr = ptr->next;
                    ptr2 = ptr2->next;
                }
            }
        }
        
        if(!ptr1){
            ptr->next = ptr2;
        }
        if(!ptr2){
            ptr->next = ptr1;
        }
        
        return head;
    }
};