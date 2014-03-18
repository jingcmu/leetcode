# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if head == None or head.next == None:
            return head
        else:
            return self.swap(head, head.next)
            
    def swap(self, left, right):
        afterRight = right.next
        right.next = left
        if afterRight != None and afterRight.next != None:
            left.next = self.swap(afterRight, afterRight.next)
        else:
            left.next = afterRight
        return right