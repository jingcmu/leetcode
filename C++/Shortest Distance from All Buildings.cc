class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> total(m,vector<int>(n,0));
        vector<vector<int>> newGrid = grid;
        int buildingNum = 0, minDist = INT_MAX;
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                // 对每个建筑进行BFS
                if(grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.push(make_pair(i,j));
                    vector<vector<int>> dist(m,vector<int>(n, 0));
                    while(!q.empty()) {
                        auto cur = q.front();
                        q.pop();
                        for(auto d : dirs) {
                            int x = cur.first+d.first, y = cur.second+d.second;
                            if(x < m && x >= 0 && y < n && y >= 0) {
                                // 跳过之前某个建筑到不了的点或建筑或障碍物
                                if(newGrid[x][y] != buildingNum) continue;
                                --newGrid[x][y];
                                dist[x][y] = dist[cur.first][cur.second] + 1;
                                total[x][y] += dist[x][y];
                                q.push(make_pair(x, y));
                            }
                        }
                    }
                    --buildingNum;
                }
            }
        }
        for(int i = 0; i<total.size(); ++i) {
            for(int j = 0; j<total[0].size(); ++j) {
                if(total[i][j] && newGrid[i][j] == buildingNum)
                    minDist = min(minDist, total[i][j]);
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
