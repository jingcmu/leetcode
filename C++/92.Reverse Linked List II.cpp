/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 思路：细心，画图
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *start, *end, *beforeStart, *afterEnd, *ptr;
        start = end = beforeStart = afterEnd = NULL;
        ptr = head; //ptr指向head，head就可以保持不动了
		//找到beforeStart的位置
        for(int i=1; i<m; i++){
            beforeStart = ptr;
            ptr = ptr->next;
        }
        start = end = ptr;
		//逆转
        for(int i=m; i<=n; i++){
            afterEnd = ptr->next;
            ptr->next = end;
            end = ptr;
            ptr = afterEnd;
        }
        if(beforeStart == NULL){
            head = end;
        }
        else{
            beforeStart->next = end;
        }
        start->next = afterEnd;
        return head;
    }
};