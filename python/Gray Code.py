class Solution:
    # @return a list of integers
    def grayCode(self, n):
        res = []
        len = 1 << n
        for i in xrange(0, len):
            res.append(i^(i>>1))
        return res