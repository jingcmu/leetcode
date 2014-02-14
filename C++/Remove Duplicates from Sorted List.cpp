First Try:
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*
其实第一种解法还不如第二种解法好, 因为delete操作没有顺便做
*/
class Solution {
public:
   ListNode *deleteDuplicates(ListNode *head) {
       ListNode *cur1, *cur2;
       cur1 = cur2 = head;				// both points are in the begining
       while(cur1) {
           while(cur1->next && cur1->val == cur1->next->val){ // if duplicate, move cur1 forward 
               cur1 = cur1->next;
           }
           cur2->next = cur1->next; // link cur2 to next element
           cur2 = cur2->next;		// move cur2 forward
		   cur1 = cur1->next;		// move cur1 forward
       }
       return head;
   }
};

Second Try:
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *ptr = head;
        while(ptr != nullptr && ptr->next != nullptr) {
            if(ptr->val == ptr->next->val) { //如果重复就跳过一个元素
                delete ptr->next;
				ptr->next = ptr->next->next;
			}
            else ptr = ptr->next;		//否则forward一个元素
        }
        return head;
    }
};