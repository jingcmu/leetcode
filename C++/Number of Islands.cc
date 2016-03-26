// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ret++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return ret;
    }
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0') return;
        grid[x][y] = '0';
        vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto dir : dirs) {
            dfs(grid, x + dir.first, y + dir.second, m, n);
        }
    }
};
