class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        c = a = 1
        b = 2
        if n == 2: 
            c = b
        for i in xrange(3, n+1):
            c = a + b
            a = b
            b = c
        return c
        