class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        start = 0
        end = len(A)-1
        mid = (start + end)/2
        while A[mid] != target and start <= end:
            if A[start] > target:
                return start
            if A[end] < target:
                return end + 1
            if A[mid] < target:
                start = mid+1
                mid = (start + end)/2
            else:
                end = mid-1
                mid = (start + end)/2
        return mid