class Solution:
    # @return an integer
    def reverse(self, x):
        res = 0
        flag = (x >= 0)
        x = abs(x)
        while x != 0:
            res = res*10 + x%10
            x /= 10
        if flag:
            return res
        else:
            return 0-res        
            