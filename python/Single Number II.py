class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        dict = {}
        for i in xrange(len(A)):
            if dict.has_key(A[i]):
                dict[A[i]] += 1
            else:
                dict[A[i]] = 1
        for k in dict:
            if dict[k] == 1:
                return k