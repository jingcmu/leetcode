/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 ˼·��ϸ�ģ���ͼ
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *start, *end, *beforeStart, *afterEnd, *ptr;
        start = end = beforeStart = afterEnd = NULL;
        ptr = head; //ptrָ��head��head�Ϳ��Ա��ֲ�����
		//�ҵ�beforeStart��λ��
        for(int i=1; i<m; i++){
            beforeStart = ptr;
            ptr = ptr->next;
        }
        start = end = ptr;
		//��ת
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