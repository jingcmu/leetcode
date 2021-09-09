class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = 0;
        vector<vector<int>> res(n);
        if(n <= 0) {
            return res;
        }
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            res[i].resize(m);
        }
        // Shift k times of last column
        for (int i = 0; i < k; i++) {
            int last_column_index = m-1-i;
            while(last_column_index < 0) {
                last_column_index += m;
            }
            // Shift last column
            int tmp = grid[n-1][last_column_index];
            for (int j = n-1; j > 0; j--) {
                grid[j][last_column_index] = grid[j-1][last_column_index];
            }
            grid[0][last_column_index] = tmp;
            
        }
        // Shift right k times of each column
        k %= m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int index = (m-k+j) % m;
                res[i][j] = grid[i][index];
            }
        }
        return res;
    }
};