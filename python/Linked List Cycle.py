# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        if head == None or head.next == None:
            return False
        slow = head.next
        fast = slow.next
        while fast != None and fast.next != None:
            if fast.next == slow:
                return True
            slow = slow.next
            fast = fast.next.next
        return False
        

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        if head == None:
            return False
        slow = head
        fast = head.next
        while fast != None and fast.next != None:
            if slow == fast:
                return True
            slow = slow.next
            fast = fast.next.next
        return False
        
