/*
traverse整个grid， 一旦发现1 就开始BFS. 对于第一个building(which is grid[i][j] == 1) 
它可以到达的地方是所有为0 的点，一旦它visited过这些点，我们update其为－1。 
对于第二个building，我们只能走那些－1的点，为什么呢？因为如果第一个点不能到达某一个点p, 
那么这个p已经不满足题目要求, 我们没必要去check这个点。。
因此最终我们traverse total 这个matrix的时候不仅要跳过那些 total[i][j] == 0 的点
（因为这些点是building或者obstacle的位置）， 而且我们还要跳过 newGrid[i][j] != canAchieve 的点
（因为这些点不能被所有的building到达，其实 canAchieve 这个变量记录了一共有多少building)。。
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty()) return -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> total(m,vector<int>(n,0));
        vector<vector<int>> newGrid = grid;
        int canAchieve = 0, minDist = INT_MAX;
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
                                if(newGrid[x][y] != canAchieve) continue;
                                --newGrid[x][y];
                                dist[x][y] = dist[cur.first][cur.second] + 1;
                                total[x][y] += dist[x][y];
                                q.push(make_pair(x, y));
                            }
                        }
                    }
                    --canAchieve;
                }
            }
        }
        for(int i = 0; i<total.size(); ++i) {
            for(int j = 0; j<total[0].size(); ++j) {
                if(total[i][j] && newGrid[i][j] == canAchieve)
                    minDist = min(minDist, total[i][j]);
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};
