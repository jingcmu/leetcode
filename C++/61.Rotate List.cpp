/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
˼·��һ��ָ�����ƶ�k����������ָ��һ���ƶ������Ͽ�����
�ѵ㣺�����Ȳ���kʱ�Ĵ���
*/
class Solution {
public:
   ListNode *rotateRight(ListNode *head, int k) {
        ListNode *ptr1, *ptr2, *res;
        int i, len;
        ptr1 = ptr2 = head;
        if(!k || !head) return head;
		//ptr1����ǰ��k���ڵ�
        for(i=0; i<k; i++) {
            ptr1 = ptr1->next;
            if(!ptr1){ //����Ѿ���NULL�ˣ���˵��List���Ȼ�����k
				i++;
                break;
            }
        }
		//���list����С�ڵ���k
        if(ptr1 == NULL) {
            len = i; //�õ�������
            k = k%len; //���µõ�k
            if(!k) return head; //���k��0���򷵻�head
			//����ptr1������ǰ��k���ڵ�
            ptr1 = head;
            for(i=0; i<k; i++) {
                ptr1 = ptr1->next;
            }
        }
		//ptr2����ptr1һͬ��ǰ�ƶ���ֱ��ptr1�ƶ������һ���ڵ�
        while(ptr1->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
		//�Ͽ�����
        res = ptr2->next;
        ptr2->next = NULL;
        ptr1->next = head;
        return res;
    }
};