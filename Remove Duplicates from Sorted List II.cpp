/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> v;
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n;
        ListNode *ptr = head;
        n = 0;
        v.clear();
        while(ptr){
            if(ptr->next && ptr->next->val == ptr->val){
                n++;
            }
            else if(n){
                n = 0;
            }
            else{
                v.push_back(ptr->val);
            }
            ptr = ptr->next;
        }
        int len = v.size();
        if(!len){
            return NULL;
        }
        head->val = v[0];
        ptr = head;
        for(int i=1; i<len; i++){
            ptr->next = new ListNode(v[i]);
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return head;
    }
};