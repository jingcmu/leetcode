/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
˼·��
������ֳ�2���֣��Ѻ�һ�뵥����reverse���ٺϲ�����������
*/
class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *fast, *slow, *half;
        half = fast = slow = head;
        if(!head || !head->next){ //С��2���ڵ�ֱ�ӷ���
            return;
        }
        while(fast && fast->next) {
            half = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        half->next = NULL;
		//�����һ������
        half = reverse(slow);
		//�ϲ�ǰһ������������ĺ�һ������
		//ǰ��������ܱ�֤ǰһ�벻��Ⱥ�һ�볤
		//(�����ڵ�ʱ����һ����һ���ڵ�)
        merge(head, half);
    }
    
	//merge��������
    void merge(ListNode *head, ListNode *half){
        ListNode *p1 = head, *p2 = half;
        while(p1->next){ 
            ListNode *tmp;
            tmp = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1->next->next = tmp;
            p1 = tmp;
        }
		p1->next = p2;
    }
    
	//������������̸�ˣ�С�ĵ������
    ListNode *reverse(ListNode *head){
        ListNode *p0, *p1, *p2;
        if(!head || !head->next) { //С��2���ڵ�ֱ�ӷ���
            return head;
        }
		//����϶���Ҫ3��ָ��ģ�һ��ͼ�������ˣ�2��ָ���ǲ��е�
        p0 = head;
        p1 = p0->next;
        p2 = p1->next;
		while(p2){
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            p2 = p2->next;
        }
		//����������β���������ֻ�������ڵ㣬while�ǽ���ȥ�ģ�
		//�����������ڵ������
        p1->next = p0;
        head->next = NULL;
        return p1;
    }
};