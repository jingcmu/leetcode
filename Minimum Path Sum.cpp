My solution:
//二维动态规划,直接在grid上做了,缺点是grid被修改了
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int height = grid.size();
        if(height == 0) return 0;
        int width = grid[0].size();
        //first line
        for(int j=1; j<width; j++){
            grid[0][j] = grid[0][j-1] + grid[0][j];
        }
        //first column
        for(int i=1; i<height; i++){
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }
        for(int i=1; i<height; i++){
            for(int j=1; j<width; j++){
                grid[i][j] = grid[i][j] + (grid[i-1][j]<grid[i][j-1]?grid[i-1][j]:grid[i][j-1]);
            }
        }
        return grid[height-1][width-1];
    }
};

//动态规划+滚动数组,不修改grid
//巧妙之处是这里不需要计算第一行和第一列的值
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		const int m = grid.size();
		const int n = grid[0].size();
		int f[n];
		fill(f, f+n, INT_MAX); // 初始值是INT_MAX，因为后面用了min 函数。
		f[0] = 0;
		for (int i = 0; i < m; i++) {
			f[0] += grid[i][0];
			for (int j = 1; j < n; j++) {
				// 左边的f[j]，表示更新后的f[j]，与公式中的f[i][j] 对应
				// 右边的f[j]，表示老的f[j]，与公式中的f[i-1][j] 对应
				f[j] = min(f[j - 1], f[j]) + grid[i][j];
			}
		}
		return f[n - 1];
	}
};