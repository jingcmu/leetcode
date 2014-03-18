# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        if l1 == None:
            return l2
        elif l2 == None:
            return l1
        if l1.val < l2.val:
            l3 = l1
            l1 = l1.next
        else:
            l3 = l2
            l2 = l2.next
        p = l3
        while l1 != None or l2 != None:
            if l1 == None:
                p.next = l2
                return l3
            if l2 == None:
                p.next = l1
                return l3
            if l1.val < l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next
        return l3
            