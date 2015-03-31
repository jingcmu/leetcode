class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        res = 0
        for c in s:
            res *= 26
            res += (ord(c) - ord('A') + 1)
        return res