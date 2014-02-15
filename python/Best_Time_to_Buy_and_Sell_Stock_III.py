class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if len(prices) == 0:
            return 0
        minPrice = prices[0]
        profit1 = []
        profit = 0
        for i in xrange(0, len(prices)):
            if prices[i] < minPrice:
                minPrice = prices[i]
            profit1.append(prices[i] - minPrice)
        maxPrice = prices[len(prices)-1]
        profit2 = 0
        for i in xrange(len(prices)-1,-1,-1):
            if prices[i] > maxPrice:
                maxPrice = prices[i] #更新maxPrice
            if maxPrice - prices[i] > profit2:
                profit2 = maxPrice - prices[i] #更新profit2
            if profit < profit1[i] + profit2:
                profit = profit1[i] + profit2 #更新profit
        return profit
