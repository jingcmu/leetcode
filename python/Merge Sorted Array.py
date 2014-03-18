class Solution:
    # @param A  a list of integers
    # @param m  an integer, length of A
    # @param B  a list of integers
    # @param n  an integer, length of B
    # @return nothing
    def merge(self, A, m, B, n):
        len = m + n
        for i in xrange(len, 0, -1):
            if n == 0:
                return
            if m == 0 or A[m-1] < B[n-1]:
                A[i-1] = B[n-1]
                n -= 1
            else:
                A[m-1] > B[n-1]
                A[i-1] = A[m-1]
                m -= 1
                