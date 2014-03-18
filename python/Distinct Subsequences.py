class Solution:
    # @return an integer
    def numDistinct(self, S, T):
        res = [[0 for j in xrange(0, len(T))] for i in xrange(0, len(S))]
        if len(S) < len(T):
            return 0
        if S[0] == T[0]:
            res[0][0] = 1
        for i in xrange(1, len(S)):
            if S[i] == T[0]:
                res[i][0] = res[i-1][0] + 1
            else:
                res[i][0] = res[i-1][0]
        for i in xrange(1, len(S)):
            for j in xrange(1, len(T)):
                if S[i] == T[j]:
                    res[i][j] = res[i-1][j] + res[i-1][j-1]
                else:
                    res[i][j] = res[i-1][j]
        return res[len(S)-1][len(T)-1]