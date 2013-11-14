//only scan once
class Solution {
public :
    int maxProfit(vector< int> &prices) {
        int min, profit = 0, len = prices.size();
        if(len) {
            min = prices[0];
        }
        for( int i=1; i<len; i++){
            profit = prices[i]-min > profit? prices[i]-min : profit;
            min = prices[i] < min? prices[i] : min;
        }
        return profit;
    }
};
