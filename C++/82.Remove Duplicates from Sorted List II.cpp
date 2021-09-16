/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*��һ�ַ���̫���ˣ������ˣ���vector��ListNode��
������������������*/
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
�ڶ��ַ�������һЩ����һ��ָ��before�����ظ�Ԫ��֮ǰ��
��Ϊ֪���ظ�Ԫ�ص�ֵ�����Ա������ظ�Ԫ��ɾ����
*/
class Solution {
	public:
	   ListNode *deleteDuplicates(ListNode *head) {
		ListNode h(-1); //һ��Ҫ��һ���ڵ�
		ListNode *ptr = head;
		ListNode *before = &h; //before��ʼ��ʱ��ָ������ڵ�
		int val;
		h.next = head;
		while(ptr && ptr->next) { //ptr��Ϊ���Ҳ�Ϊ���һ���ڵ�
			if(ptr->val != ptr->next->val) {
				before = ptr;
				ptr = ptr->next;
			}
			else {
				val = ptr->val;
				while(ptr->val == val) { //ɾ�������ظ�Ԫ��
					before->next = ptr = ptr->next;
					if(ptr == NULL) break;
				}
			}
		}
		return h.next;
	}
};