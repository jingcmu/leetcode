/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode *merge2Lists(ListNode *list1, ListNode *list2){
        ListNode *list = NULL, *curList;
        while(list1 != NULL && list2 != NULL){
            int value = 0;
            if(list1->val < list2->val){
                value = list1->val;
                list1 = list1->next;
            }
            else{
                value = list2->val;
                list2 = list2->next;
            }
            if(!list){
                list = new ListNode(value);
                curList = list;
            }
            else{
                curList->next = new ListNode(value);
                curList = curList->next;
            }
        }
        ListNode *l = NULL;
        if(list1){
            l = list1; 
        }
        else if(list2){
            l = list2;
        }
        if(list){
            curList->next = l;
        }
        else{
            list = l;
        }
        return list;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = lists.size();
        if(!len){
            return NULL;
        }
        for(int i=1; i<len; i++){
            lists[i] = merge2Lists(lists[i-1], lists[i]);
        }
        return lists[len-1];
    }
};