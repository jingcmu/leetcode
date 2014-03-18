# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def helper(self, left, right):
        if left == None and right == None:
            return True
        elif left == None or right == None or left.val != right.val:
            return False
        return self.helper(left.left, right.right) \
                and self.helper(left.right, right.left)
        
    def isSymmetric(self, root):
        if root == None:
            return True
        else:
            return self.helper(root.left, root.right)