class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        if (m == 0) {
            return 0;
        }
        
        int n = accounts[0].size();
        int richest = 0;        
        
        for (int i = 0; i < m; i++) {            
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += accounts[i][j];
            }
            richest = max(richest, sum);
        }
        
        return richest;
    }
};