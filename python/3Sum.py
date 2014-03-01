class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        res = []
        v_last = []
        if len(num) < 3:
            return res
        num.sort()
        for i in xrange(0, len(num)):
            target = 0 - num[i]
            head = i + 1
            tail = len(num) - 1
            if i > 0 and num[i] == num[i-1]:
                continue
            while head < tail:
                v = []
                if num[head] + num[tail] == target:
                    v = [num[i], num[head], num[tail]]
                    head += 1
                    tail -= 1
                    if v != v_last:
                        v_last = v
                        res.append(v)
                elif num[head] + num[tail] < target:
                    head += 1
                else:
                    tail -= 1
        return res