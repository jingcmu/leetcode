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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<ListNode *> vk, v;
        int n = 0;
        vk.clear();
        v.clear();
        if(!head){
            return NULL;
        }
        while(head){
            vk.push_back(head);
            n++;
            if(n == k){
                n = 0;
                reverse(vk.begin(), vk.end());
                for(int i=0; i<k; i++){
                    v.push_back(vk[i]);
                }
                vk.clear();
            }
            head = head->next;
        }
        if(vk.size()){
            for(int i=0; i<vk.size(); i++){
                v.push_back(vk[i]);
            }
            vk.clear();
        }
        for(int i=0; i<(int)v.size()-1; i++){
            v[i]->next = v[i+1];
        }
        v[v.size()-1]->next = NULL;
        return v[0];
    }
};