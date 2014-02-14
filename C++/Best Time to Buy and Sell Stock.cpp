/*
扫描一遍，记录下遇到的min price，拿当前price减去min price，
记录下最大的profit
*/
class Solution {
public :
    int maxProfit(vector< int> &prices) {
        int min_price, profit = 0, len = prices.size();
        if(len) min_price = prices[0]; //初始化最小价格
        for(int i=1; i<len; i++){
			//更新最小价格
			min_price = min(prices[i], min_price);
			//用当前最小价格计算最大利润
            profit = prices[i]-min_price > profit? prices[i]-min_price : profit;
        }
        return profit;
    }
};
