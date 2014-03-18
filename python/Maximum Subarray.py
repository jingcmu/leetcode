class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        if A == None:
            return 0
        max2now = A[0]
        sum2now = 0
        for i in xrange(0, len(A)):
            sum2now = max(sum2now, 0)
            sum2now += A[i]
            max2now = max(max2now, sum2now)
        return max2now