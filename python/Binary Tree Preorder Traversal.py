# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        res = []
        d = []
        if root == None:
            return res
        d.append(root)
        while len(d) != 0:
            node = d.pop()
            res.append(node.val)
            if node.right != None:
                d.append(node.right)
            if node.left != None:
                d.append(node.left)
        return res
            