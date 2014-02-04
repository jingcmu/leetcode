/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
/*
扫描两遍：
第一遍的时候，就简单得把新节点插入到相应的旧节点后面，
第二遍的时候，拷贝random指针
然后，把得到的链表分拆成新旧两个链表
*/
class Solution {
public:
	//分拆链表，下面还有另外一种写法
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
		//扫描第一遍，把新节点插入到相应的旧节点后面
        while(ptr1) {
            ptr2 = new RandomListNode(ptr1->label);
            ptr2->next = ptr1->next;  
            ptr1->next = ptr2; //拷贝节点插入到ptr1后面
            ptr1 = ptr2->next;
        }
        //扫描第二遍，拷贝random指针
        ptr1 = head;
        while(ptr1) {
            if(ptr1->random) {
                ptr1->next->random = ptr1->random->next;
            }
            ptr1 = ptr1->next->next;
        }
        //分拆两个链表
        return removeClone(head);
    }
};



	//分拆链表的第二种写法
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