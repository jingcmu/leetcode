class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        res = 0;
        while n != 0:
            res += (n & 1)
            n >>= 1
        return res