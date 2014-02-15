class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        profit = 0;
        for i in xrange(len(prices)-1):
            diff = prices[i+1] - prices[i]
            if diff > 0:
                profit += diff
        
        return profit