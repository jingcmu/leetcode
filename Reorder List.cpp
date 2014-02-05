/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：
把链表分成2部分，把后一半单链表reverse，再合并两个单链表
*/
class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *fast, *slow, *half;
        half = fast = slow = head;
        if(!head || !head->next){ //小于2个节点直接返回
            return;
        }
        while(fast && fast->next) {
            half = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        half->next = NULL;
		//逆序后一半链表
        half = reverse(slow);
		//合并前一半链表和逆序后的后一半链表
		//前面的逆序能保证前一半不会比后一半长
		//(奇数节点时，后一半会多一个节点)
        merge(head, half);
    }
    
	//merge两个链表
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
    
	//逆序是老生常谈了，小心点就行了
    ListNode *reverse(ListNode *head){
        ListNode *p0, *p1, *p2;
        if(!head || !head->next) { //小于2个节点直接返回
            return head;
        }
		//逆序肯定是要3个指针的，一画图就明白了，2个指针是不行的
        p0 = head;
        p1 = p0->next;
        p2 = p1->next;
		while(p2){
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            p2 = p2->next;
        }
		//逆序最后的收尾工作，如果只有两个节点，while是进不去的，
		//这里做两个节点的逆序
        p1->next = p0;
        head->next = NULL;
        return p1;
    }
};