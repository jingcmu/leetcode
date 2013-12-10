/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode* removeClone(RandomListNode* head)  
    {  
        RandomListNode* ptr1 = head, *ptr2 = head->next, *ptr;
        ptr = ptr2;
        while(ptr1) {  
            ptr1->next = ptr1->next->next;
            ptr1 = ptr1->next;
            if(ptr2->next){
                ptr2->next = ptr2->next->next;
            }
            ptr2 = ptr2->next;
        }  
        return ptr;  
    }  
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        RandomListNode *ptr1 = head, *ptr2, *ptr;
        while(ptr1){
            ptr2 = new RandomListNode(ptr1->label);
            ptr2->next = ptr1->next;  
            ptr1->next = ptr2; //拷贝节点插入到ptr1后面
            ptr1 = ptr2->next;
        }
        //拷贝random指针
        ptr1 = head;
        while(ptr1){
            if(ptr1->random){
                ptr1->next->random = ptr1->random->next;
            }
            ptr1 = ptr1->next->next;
        }
        //分拆两个链表
        return removeClone(head);
    }
};