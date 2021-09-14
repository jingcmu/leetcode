//��̬�滮
//���һ�г������ϰ��Ҫ���ϰ��ﴦ��Ϊ0�������λ�ü��㷽������
//�Ե�һ�е�һ�е���������
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
        for(int i=0; i<width; i++){ //�����һ��,ֻҪ�����ϰ������ȫΪ0
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
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int h = obstacleGrid.size();
        if(h == 0) return 0;
        int w = obstacleGrid[0].size();
        vector<vector<int>> f(h+1, vector<int>(w+1, 0));
        return dfs(w, h, obstacleGrid, f);
    } 
private:
    int dfs(int x, int y, vector<vector<int> > &obstacleGrid, vector<vector<int>> &f) {
        if(x < 1 || y < 1) return 0;
        if(obstacleGrid[y-1][x-1] == 1) return 0;
        if(x == 1 && y == 1) return 1;
        if(f[y][x] != 0) return f[y][x];
        else {
            f[y][x] = dfs(x-1, y, obstacleGrid, f) + dfs(x, y-1, obstacleGrid, f);
            return f[y][x];
        }
    }
    
};
