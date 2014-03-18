# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a boolean
    def getDepth(self, root):
        if root == None:
            return 0
        else:
            r = self.getDepth(root.right)
            l = self.getDepth(root.left)
            return max(r,l)+1
        
    def isBalanced(self, root):
        if root == None:
            return True
        diff = self.getDepth(root.left) - self.getDepth(root.right)
        if diff > 1 or diff < -1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
        