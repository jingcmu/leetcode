class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        res = []
        if numRows == 0:
            return res
        cur = [1]
        cur1 = copy.deepcopy(cur)
        res.append(cur1)
        for _ in xrange(1, numRows):
            for j in xrange(len(cur)-1, 0, -1):
                cur[j] = cur[j-1] + cur[j]
            cur.append(1)
            cur1 = copy.deepcopy(cur)
            res.append(cur1)
        return res
        