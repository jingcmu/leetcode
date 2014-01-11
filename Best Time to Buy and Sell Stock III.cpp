class Solution {
public:
   int maxProfit(vector<int> &prices, int a, int b, int *start, bool flag){
        int min2now, max = 0, s = a;
		if(flag){
			*start = a;
		}
        if(a >= b){
            return 0;
        }
        min2now = prices[a];
        for(int i=a; i<=b; i++){
            if(min2now > prices[i]){
                min2now = prices[i];
				s = i;
            }
            if(max < prices[i] - min2now){
                max = prices[i] - min2now;
				if(flag){
					*start = s;
				}
            }
        }
        return max;
    }

    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = prices.size();
        int start, end;
        int max_profit = 0, profit, profit_right, profit_left;
        if(len < 2){
            return 0;
        }
        profit_left = maxProfit(prices, 0, len-1, &start, true);
        if(profit_left > max_profit){
            max_profit = profit_left;
        }
		else{
			return 0;
		}
        while(start < len-1){
            profit_right = maxProfit(prices, 0, start-1, &start, false);
            profit = profit_right + profit_left;
            if(profit > max_profit){
                max_profit = profit;
            }
            profit_left = maxProfit(prices, start+1, len-1, &start, true);
			if(!profit_left){
				break;
			}
        }
        return max_profit;
    }
};