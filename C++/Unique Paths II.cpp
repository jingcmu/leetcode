//动态规划
//如果一行出现了障碍物，要把障碍物处置为0，后面的位置计算方法类似
//对第一行第一列单独处理了
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int height = obstacleGrid.size();
        if(!height){
            return 0;
        }
        int width = obstacleGrid[0].size(), valid = 1;
        vector<int> pathNum;
        if(obstacleGrid[0][0] || obstacleGrid[height-1][width-1]) return 0;
        for(int i=0; i<width; i++){ //处理第一行,只要出现障碍物后面全为0
            if(obstacleGrid[0][i]){
                valid = 0;
            }
            pathNum.push_back(valid);
        }
        valid = 1;
        for(int i=1; i<height; i++){
            if(obstacleGrid[i][0]) valid = 0;
            pathNum[0] = valid;
            for(int j=1; j<width; j++){
                if(obstacleGrid[i][j]) pathNum[j] = 0;
                else pathNum[j] = pathNum[j] + pathNum[j-1];
            }
        }
        return pathNum[width-1];
    }
};

//DFS + memoization
class Solution {
public:
    int uniquePaths(int m, int n) {
        w = m;
        h = n;
        f.resize(h+1);
        for(int i=0; i<=h; i++) {
            f[i].resize(w+1);
        }
        return dfs(1, 1);
    }
private:
    int dfs(int x, int y) {
        if(x > w || y > h) return 0;
        if(x == w && y == h) {
            return 1;
        }
        if(f[y][x]) return f[y][x];
        else {
            f[y][x] = dfs(x+1, y) + dfs(x, y+1);
            return f[y][x];
        }
    }
    int w, h;
    vector<vector<int>> f;
};