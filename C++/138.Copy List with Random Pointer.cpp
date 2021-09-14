/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/*
ɨ�����飺
��һ���ʱ�򣬾ͼ򵥵ð��½ڵ���뵽��Ӧ�ľɽڵ���棬
�ڶ����ʱ�򣬿���randomָ��
Ȼ�󣬰ѵõ�������ֲ���¾���������
*/
class Solution {
public:
	//�ֲ��������滹������һ��д��
    RandomListNode* removeClone(RandomListNode* head) {
        RandomListNode* ptr1 = head, *ptr2 = head->next, *ptr;
        ptr = ptr2;
        while(ptr1) { 
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            if(ptr2->next) {
                ptr2->next = ptr2->next->next;
            }
            ptr2 = ptr2->next;
        }  
        return ptr; 
    }
	
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        RandomListNode *ptr1 = head, *ptr2, *ptr;
		//ɨ���һ�飬���½ڵ���뵽��Ӧ�ľɽڵ����
        while(ptr1) {
            ptr2 = new RandomListNode(ptr1->label);
            ptr2->next = ptr1->next;  
            ptr1->next = ptr2; //�����ڵ���뵽ptr1����
            ptr1 = ptr2->next;
        }
        //ɨ��ڶ��飬����randomָ��
        ptr1 = head;
        while(ptr1) {
            if(ptr1->random) {
                ptr1->next->random = ptr1->random->next;
            }
            ptr1 = ptr1->next->next;
        }
        //�ֲ���������
        return removeClone(head);
    }
};

	//�ֲ�����ĵڶ���д��
    RandomListNode* removeClone(RandomListNode* head) {
        RandomListNode* ptr1 = head, *ptr2 = head->next, *ptr;
        ptr = ptr2;
        while(ptr2->next) { 
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            ptr2->next = ptr2->next->next;
            ptr2 = ptr2->next;
        }  
        ptr1->next = ptr2->next = NULL;
        return ptr; 
    }