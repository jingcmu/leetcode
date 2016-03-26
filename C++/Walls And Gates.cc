// BFS
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (rooms[r][c] == 0) // A gate
                    q.push(make_pair(r, c));
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // A good way to define dirs
        while(!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            // Try each direction
            for (auto dir : dirs) {
                int x = r + dir.first, y = c + dir.second;
                if (x < 0 || y < 0 || x >= m || y >= n || rooms[x][y] <= rooms[r][c]) continue;
                rooms[x][y] = rooms[r][c] + 1;
                q.push(make_pair(x,y));
            }
        }
    }
};
