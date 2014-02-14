/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
把数据分成2个链表，小于x的放到smaller中，大于x的放到bigger中
因为，链表是顺序放的，所以他们之间的相对顺序是不会变的
smaller_head和biger_head是头指针，smaller_ptr和biger_ptr是用来遍历的指针
返回的时候，注意两个链表是否为空的情况即可
*/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *smaller_head, *biger_head, *smaller_ptr, *biger_ptr;
        smaller_head = biger_head = smaller_ptr = biger_ptr = NULL;
        while(head) {
			//把小于x的元素放到smaller这个链表中
            if(head->val < x){
				//根据smaller是否为空链表来操作
                if(!smaller_head) smaller_head = smaller_ptr = head;
                else{
                    smaller_ptr->next = head;
                    smaller_ptr = smaller_ptr->next;
                } 
            }
			//把大于等于x的元素放到bigger这个链表中
            else{
				//根据biger是否为空链表来操作
                if(!biger_head) biger_head = biger_ptr = head;
                else{
                    biger_ptr->next = head;
                    biger_ptr = biger_ptr->next;
                } 
            }
            head = head->next;
        }
		//根据链表为空的情况返回结果
        if(!smaller_head && !biger_head) return NULL;
        if(biger_head) biger_ptr->next = NULL;
        if(smaller_head){
            smaller_ptr->next = biger_head;
            return smaller_head;
        }
        return biger_head;
    }
};