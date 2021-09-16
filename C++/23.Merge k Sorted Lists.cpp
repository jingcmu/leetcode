/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
merge k ����ʵ���ǲ��ϵ�merge���У�
merge���У����˵㼼�ɣ�����Ҫ�ж϶���NULL��
*/
class Solution {
public:
    ListNode *merge2Lists(ListNode *list1, ListNode *list2){
        ListNode head(-1), *curList = &head;
        while(list1 != NULL || list2 != NULL){
            int value1 = (list1 == NULL? INT_MAX:list1->val);
			int value2 = (list2 == NULL? INT_MAX:list2->val);
            if(value1 < value2){
                curList->next = list1;
                list1 = list1->next;
				curList = curList->next;
            }
            else{
                curList->next = list2;
                list2 = list2->next;
				curList = curList->next;
            }
        }
        return head.next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int len = lists.size();
        if(!len) return NULL;
        for(int i=1; i<len; i++){
            lists[i] = merge2Lists(lists[i-1], lists[i]);
        }
        return lists[len-1];
    }
};