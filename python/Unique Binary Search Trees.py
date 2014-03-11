class Solution:
    # @return an integer
    def numTrees(self, n):
        if n == 0:
            return 1
        if n == 1:
            return 1
        res = 0
        for i in xrange(n):
            res += self.numTrees(i)*self.numTrees(n-i-1)
        return res