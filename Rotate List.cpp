/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
思路：一个指针先移动k，接着两个指针一起移动，最后断开重连
难点：链表长度不足k时的处理
*/
class Solution {
public:
   ListNode *rotateRight(ListNode *head, int k) {
        ListNode *ptr1, *ptr2, *res;
        int i, len;
        ptr1 = ptr2 = head;
        if(!k || !head) return head;
		//ptr1先往前走k个节点
        for(i=0; i<k; i++) {
            ptr1 = ptr1->next;
            if(!ptr1){ //如果已经是NULL了，则说明List长度还不足k
				i++;
                break;
            }
        }
		//如果list长度小于等于k
        if(ptr1 == NULL) {
            len = i; //得到链表长度
            k = k%len; //重新得到k
            if(!k) return head; //如果k是0，则返回head
			//否则ptr1重新往前走k个节点
            ptr1 = head;
            for(i=0; i<k; i++) {
                ptr1 = ptr1->next;
            }
        }
		//ptr2随着ptr1一同往前移动，直到ptr1移动到最后一个节点
        while(ptr1->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
		//断开重连
        res = ptr2->next;
        ptr2->next = NULL;
        ptr1->next = head;
        return res;
    }
};