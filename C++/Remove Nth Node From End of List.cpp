/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
先让current往前走n-1步，再让remove往前跟着走，
为什么是n-1步，只要一画图就知道了，因为remove要指向删除的节点的前一个节点
*/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode beforeHead(-1);
        ListNode *current = head, *remove = &beforeHead;
        beforeHead.next = head;
        for(int i=0; i<n-1; i++) {
            current = current->next; //先让current往前走n-1步
			if(current == NULL) return head;
        }
        while(current->next) {
            current = current->next;
            remove = remove->next;
        }
        remove->next = remove->next->next;
        return beforeHead.next;
    }
};