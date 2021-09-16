/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
�ݹ�棺
�����Ҫ��ס
*/
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2)
			return head;
		ListNode *next_group = head;
		//���ʣ��Ľڵ��������k�����򷵻�head
		for (int i = 0; i < k; ++i) {
			if (next_group)
				next_group = next_group->next;
			else
				return head;
		}
		// next_group is the head of next group
		// new_next_group is the new head of next group after reversion
		ListNode *new_next_group = reverseKGroup(next_group, k);
		ListNode *prev = NULL, *cur = head;
		while (cur != next_group) {
			ListNode *next = cur->next;
			//��һ���ڵ���ָ��new_next_group������ÿ���ڵ���ָ��ǰһ���ڵ�
			cur->next = prev ? prev : new_next_group;
			//prev��cur����ƶ�һ��Ԫ��
			prev = cur; 
			cur = next;
		}
		return prev; // prev will be the new head of this group
	}
};

/*������*/
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) return head;
		ListNode dummy(-1);
		dummy.next = head;
		//prevָ��ת����ǰ��һ���ڵ�
		for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
			for (int i = 1; i < k && end; i++)
				end = end->next;
			if (end == nullptr) break; // ����k ����end�Ǳ�����
			prev = reverse(prev, prev->next, end); //����
		}
		return dummy.next;
	}
	// prev ��first ǰһ��Ԫ��, [begin, end] �����䣬��֤���߶���Ϊnull
	// ���ط�ת��ĵ�����1 ��Ԫ��
	ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
		ListNode *end_next = end->next;
		//���д��̫��ƽ�׽����ˣ����Ƽ�����������д�˺����İ汾
		for (ListNode *p = begin, *cur = p->next, *next = cur->next;
			cur != end_next;
			p = cur, cur = next, next = next ? next->next : nullptr) {
			cur->next = p;
		}
		begin->next = end_next;
		prev->next = end;
		return begin;
	}
};

//��д������ķ�ת����
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) return head;
		ListNode dummy(-1);
		dummy.next = head;
		//prevָ��ת����ǰ��һ���ڵ�
		for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
			for (int i = 1; i < k && end; i++)
				end = end->next;
			if (end == nullptr) break; // ����k ����end�Ǳ�����
			prev = reverse(prev, prev->next, end); //����
		}
		return dummy.next;
	}
	// prev ��first ǰһ��Ԫ��, [begin, end] �����䣬��֤���߶���Ϊnull
	// ���ط�ת��ĵ�����1 ��Ԫ��
	ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
		ListNode *end_next = end->next;
		ListNode *before_cur = begin, *cur = begin->next, *next = cur->next;
		while(cur != end_next) {	//ע�����������������
			cur->next = before_cur; //cur���ָ��before_cur
			before_cur = cur;
			cur = next;
			next = next? next->next:NULL;
		}
		begin->next = end_next;
		prev->next = end;
		return begin;
	}
};

/*
��������������Ҫ�󣬵����ܹ���
�ѽڵ㶼�ŵ�vector�У�����vector���з�ת��Ȼ������������Ҳ����ʵ��
*/
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
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