class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if len(prices) == 0:
            return 0
        minPrice = prices[0]
        profit = 0
        for i in xrange(1,len(prices)):
            if prices[i] < minPrice:
                minPrice = prices[i]
            if prices[i]-minPrice > profit:
                profit = prices[i]-minPrice
        return profit

#test part
S = Solution()
Prices = [6,1,3,2,4,7]
print S.maxProfit(Prices)