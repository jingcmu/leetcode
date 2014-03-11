# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        if root == None:
            return
        queue = []
        queue.append(root)
        while len(queue):
            size = len(queue)
            left = queue[0]
            if left.left != None:
                queue.append(left.left)
            if left.right != None:
                queue.append(left.right)
            for i in xrange(1, size):
                right = queue[i]
                if right.left != None:
                    queue.append(right.left)
                if right.right != None:
                    queue.append(right.right)
                left.next = right
                left = right
            queue = queue[size:]
                
        