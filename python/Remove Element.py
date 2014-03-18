class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        start = 0
        for i in xrange(len(A)):
            if A[i] != elem:
                A[start] = A[i]
                start += 1
        return start