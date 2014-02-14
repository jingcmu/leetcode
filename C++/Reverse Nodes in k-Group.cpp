/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
递归版：
很巧妙，要记住
*/
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2)
			return head;
		ListNode *next_group = head;
		//如果剩余的节点个数不足k个，则返回head
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
			//第一个节点后继指向new_next_group，后面每个节点后继指向前一个节点
			cur->next = prev ? prev : new_next_group;
			//prev和cur向后移动一个元素
			prev = cur; 
			cur = next;
		}
		return prev; // prev will be the new head of this group
	}
};

/*迭代版*/
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) return head;
		ListNode dummy(-1);
		dummy.next = head;
		//prev指向反转序列前的一个节点
		for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
			for (int i = 1; i < k && end; i++)
				end = end->next;
			if (end == nullptr) break; // 不足k 个，end是闭区间
			prev = reverse(prev, prev->next, end); //返回
		}
		return dummy.next;
	}
	// prev 是first 前一个元素, [begin, end] 闭区间，保证三者都不为null
	// 返回反转后的倒数第1 个元素
	ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
		ListNode *end_next = end->next;
		//这段写的太不平易近人了，不推荐，下面有重写此函数的版本
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

//重写迭代版的反转函数
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == nullptr || head->next == nullptr || k < 2) return head;
		ListNode dummy(-1);
		dummy.next = head;
		//prev指向反转序列前的一个节点
		for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
			for (int i = 1; i < k && end; i++)
				end = end->next;
			if (end == nullptr) break; // 不足k 个，end是闭区间
			prev = reverse(prev, prev->next, end); //返回
		}
		return dummy.next;
	}
	// prev 是first 前一个元素, [begin, end] 闭区间，保证三者都不为null
	// 返回反转后的倒数第1 个元素
	ListNode* reverse(ListNode *prev, ListNode *begin, ListNode *end) {
		ListNode *end_next = end->next;
		ListNode *before_cur = begin, *cur = begin->next, *next = cur->next;
		while(cur != end_next) {	//注意这里的条件！！！
			cur->next = before_cur; //cur后继指向before_cur
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
这种做法不符合要求，但是能过，
把节点都放到vector中，利用vector进行反转，然后再连起来，也容易实现
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