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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *cur, *cur_left = head, *ptr_left, *ptr;
		bool flag;
        if(!head || !head->next){
            return head;
        }
        cur = cur_left->next;
        while(cur){
			flag = true;
            if(cur->val < head->val){
                cur_left->next = cur->next;
                cur->next = head;
                head = cur;
                cur = cur_left->next;
				continue;
            }
            ptr_left = head;
            ptr = ptr_left->next;
            while(cur && ptr != cur){
                if(cur->val < ptr->val){
                    cur_left->next = cur->next;
                    cur->next = ptr;
                    ptr_left->next = cur;
                    cur = cur_left->next;
					flag = false;
					break;
                }
                ptr_left = ptr_left->next;
                ptr = ptr_left->next;
            }
			if(flag){
				cur_left = cur_left->next;
				if(cur_left){
					cur = cur_left->next;
				}
			}
        }
        return head;
    }
};