# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param num, a list of integers
    # @return a tree node
    def helper(self, num, left, right):
        mid = (left+right)/2
        if left > right:
            return None
        root = TreeNode(num[mid])
        root.left = self.helper(num, left, mid-1)
        root.right = self.helper(num, mid+1, right)
        return root
    
    def sortedArrayToBST(self, num):
        return self.helper(num, 0, len(num)-1)