/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        int len = 0;
        
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        
        len = v.size();
        for(int i = 0; i < len/2; i++) {
            if(v[i] != v[len-i-1]) {
                return false;
            }
        }
        
        return true;
    }
};