#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(nullptr) {}
};

ListNode * ReverseList1( ListNode * ptr )
{
    ListNode * temp;
    ListNode * previous = NULL;
    while(ptr != NULL) {
        temp = ptr->next;
        ptr->next = previous;
        previous = ptr;
        ptr = temp;
    }
    return previous;
}

ListNode * ReverseList( ListNode * ptr, ListNode *last)
{
   if(ptr == nullptr) return last;
   ListNode *next = ptr->next;
   ptr->next = last;
   return ReverseList(next, ptr);
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if(head == nullptr || head->next == nullptr|| k == 1) return head;
    ListNode *pre = head, *ptr = head->next, *next;
    for(int i=1; i<k && ptr!=nullptr; i++) {
        next = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = next;
    }
    head->next = reverseKGroup(ptr, k);
    return pre;
}

int main() {
	ListNode l1(1), l2(2), l3(3), l4(4), l5(5), l6(6);
	l1.next = &l2;
	// l2.next = &l3; 
	// l3.next = &l4;
	// l4.next = &l5;
	// l5.next = &l6;
	ListNode *root = &l1;
	root = reverseKGroup(root, 3);
	for(ListNode *ptr = root; ptr != nullptr; ptr = ptr->next) {
		cout << ptr->val << endl;
	}
	return 0;
}
