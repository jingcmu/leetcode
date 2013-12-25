/*
扫描一遍，记录下遇到的min price，拿当前price减去min price，
记录下最大的profit
*/
class Solution {
public :
    int maxProfit(vector< int> &prices) {
        int min_price, profit = 0, len = prices.size();
        if(len) {
            min_price = prices[0];
        }
        for(int i=1; i<len; i++){
            profit = prices[i]-min_price > profit? prices[i]-min_price : profit;
            min_price = min(prices[i], min);
        }
        return profit;
    }
};
