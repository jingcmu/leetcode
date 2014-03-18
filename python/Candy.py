class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        size = len(ratings)
        candys = [1 for i in xrange(size)]
        for i in xrange(1, size):
            if ratings[i] > ratings[i-1]:
                candys[i] = candys[i-1] + 1
        res = candys[size-1]
        for i in xrange(size-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                candys[i] = max(candys[i+1] + 1, candys[i])
            res += candys[i]
        return res