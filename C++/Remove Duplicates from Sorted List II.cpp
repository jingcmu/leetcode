/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*第一种方法太弱了，弱爆了，用vector放ListNode，
搞得这题像是数组操作*/
class Solution {
private:
    vector<int> v;
public:
    ListNode *deleteDuplicates(ListNode *head) {
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
        for(int i=1; i<len; i++) {
            ptr->next = new ListNode(v[i]);
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return head;
    }
};

Second Try:
/*
第二种方法正常一些，用一个指针before放在重复元素之前，
因为知道重复元素的值，所以遍历把重复元素删除完
*/
class Solution {
	public:
	   ListNode *deleteDuplicates(ListNode *head) {
		ListNode h(-1); //一定要多一个节点
		ListNode *ptr = head;
		ListNode *before = &h; //before开始的时候指向这个节点
		int val;
		h.next = head;
		while(ptr && ptr->next) { //ptr不为空且不为最后一个节点
			if(ptr->val != ptr->next->val) {
				before = ptr;
				ptr = ptr->next;
			}
			else {
				val = ptr->val;
				while(ptr->val == val) { //删除所有重复元素
					before->next = ptr = ptr->next;
					if(ptr == NULL) break;
				}
			}
		}
		return h.next;
	}
};