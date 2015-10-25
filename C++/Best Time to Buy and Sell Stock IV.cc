/*
diff是第i天price 减去 第i-1天的price: p[i] - p[i-1]

local[i][j] = max(global[i-1][j-1] + max(diff,0), local[i-1][j]+diff)
比较 1. 考虑从global[i-1][j-1]扩展过来，分两种情况 a)diff大于0,则最优值必然可以增加diff* 否则,b)最优值不变** vs 
2. 若不允许增加交易次数, 则只能把卖单从第i-1天移到第i天
*: 因为可以增加一次交易，不管第i-1天有没有卖过股票，假如卖过，则晚卖一天（不增加交易数），假如没卖过，则i-1天买入，
i天卖出（增加一次交易）
**: 此时，第i天的卖出交易显然不可能最优

global[i][j] = max(local[i][j], global[i-1][j])
比较 1. 加入第i天  vs  2. 到第i-1天，upto jth交易的最优值
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (size < 2 || k == 0) return 0;
        if (k > size / 2) {
          int sum = 0;
          for (int i=1; i<prices.size(); i++) {
			      int diff = prices[i] - prices[i-1];
			      if(diff > 0) sum += diff;
		      }
		      return sum;
        }
        vector<vector<int> > local(size, vector<int>(k+1,0));
        vector<vector<int> > global(size, vector<int>(k+1,0));
        for (int i = 1; i < size; i++) {
          int diff = prices[i] - prices[i-1];
          for (int j = 1; j <= k; j++) {
            local[i][j] = max(global[i-1][j-1] + max(diff,0), local[i-1][j] + diff);
            global[i][j] = max(local[i][j], global[i-1][j]);
          }
        }
        return global[size-1][k];
    }
};
