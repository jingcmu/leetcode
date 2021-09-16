class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        ListNode res(0);
        res.next = head;
        ListNode* last = &res;
        // last保持在head前一个位置
        while(head) {
        	if(head->val == val) {
        		last->next = head->next;
			}
			else {
				last = head;
			}
			head = head->next;
		}
		return res.next;
    }
};