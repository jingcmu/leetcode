/*
思路：O(n平方)的方法，对每个点进行分割，算出这个点两边的最大利润相加
O(n)的方法，先正向算出从起点开始到每个点的最大利润，再逆向算出从每个点开始到终点的最大利润
进而就得出了最大利润，以第i点进行分割，i点不可能同时为前段的终点和后段的起点，所以不用担心
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) 
	{
		vector<int> profit(prices.size());
		int min_price = INT_MAX;
		//先得到从左到右的最大利润(起点固定)
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < min_price) min_price = prices[i]; //更新左起最小price
			profit[i] = max(profit[i], prices[i]-min_price); //更新最大利润
		}
		//再得到从右到左的最大利润(终点固定)
		int max_price = INT_MIN , max_profit = 0, res = 0;
		for (int i = prices.size() - 1; i >= 0 ; i--) {
			if (prices[i] > max_price) max_price = prices[i]; //更新右起最大price
			else max_profit = max(max_profit, max_price - prices[i]); //更新最大利润
			res = max(profit[i]+ max_profit, res); 
		}
		return res;
	}
};