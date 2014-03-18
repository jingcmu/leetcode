# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    visit = {}
    def cloneGraph(self, node):
        if node == None:
            return None
        if self.visit.has_key(node):
            return self.visit[node]
        firstNode = UndirectedGraphNode(node.label)
        self.visit[node] = firstNode
        for i in xrange(len(node.neighbors)):
            firstNode.neighbors.append(self.cloneGraph(node.neighbors[i]))
        return firstNode