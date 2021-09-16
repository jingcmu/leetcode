/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
����current��ǰ��n-1��������remove��ǰ�����ߣ�
Ϊʲô��n-1����ֻҪһ��ͼ��֪���ˣ���ΪremoveҪָ��ɾ���Ľڵ��ǰһ���ڵ�
*/
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode beforeHead(-1);
        ListNode *current = head, *remove = &beforeHead;
        beforeHead.next = head;
        for(int i=0; i<n-1; i++) {
            current = current->next; //����current��ǰ��n-1��
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