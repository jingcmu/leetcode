/**
这道题的解法要用递归和DP来解，用DP的原因是为了提高效率，避免重复运算。
我们需要维护一个二维动态数组dp，其中dp[i][j]表示数组中以(i,j)为起点的最长递增路径的长度，
初始将dp数组都赋为0，当我们用递归调用时，遇到某个位置(x, y), 如果dp[x][y]不为0的话，
我们直接返回dp[x][y]即可，不需要重复计算。我们需要以数组中每个位置都为起点调用递归来做，
比较找出最大值。在以一个位置为起点用DFS搜索时，对其四个相邻位置进行判断，
如果相邻位置的值大于上一个位置，则对相邻位置继续调用递归，并更新一个最大值，
搜素完成后返回即可
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int res = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(i,j,matrix,dp));
            }
        }
        return res;
    }
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[x][y]) return dp[x][y];
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        // 本题巧妙的地方在于mx的引入
        int mx = 1;
        for (auto dir : dirs) {
            int x1 = x + dir.first, y1 = y + dir.second;
            if (x1 < 0 || x1 > m - 1 || y1 < 0 || y1 > n - 1 ||
                matrix[x][y] >= matrix[x1][y1]) continue;
            mx = max(mx, dfs(x1,y1,matrix,dp) + 1);
        }
        dp[x][y] = mx;
        return mx;
    }
};
