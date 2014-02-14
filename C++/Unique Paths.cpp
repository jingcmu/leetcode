My solution:
//动态规划+滚动数组
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                v[j] = v[j] + v[j-1];
            }
        }
        return v[n-1];
    }
};

//DFS
//思路就是，m n这个方格可能是从m-1 n过来的，也可能是从m n-1过来的
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) return 0; // 终止条件
		if (m == 1 && n == 1) return 1; // 收敛条件
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};

//所谓的备忘录法，其实这个方法以前也用过，只是不知道叫这个名字
class Solution {
public:
	int uniquePaths(int m, int n) {
		// 0 行和0 列未使用
		this->f = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
		return dfs(m, n);
	}
private:
	vector<vector<int> > f; // 缓存
	int dfs(int x, int y) {
		if (x < 1 || y < 1) return 0; // 数据非法，终止条件
		if (x == 1 && y == 1) return 1; // 回到起点，收敛条件
		return getOrUpdate(x - 1, y) + getOrUpdate(x, y - 1);
	}
	//这个函数的作用就是看能不能查表得到，查表没有的才递归
	int getOrUpdate(int x, int y) {
		if (f[x][y] > 0) return f[x][y];
		else return f[x][y] = dfs(x, y);
	}
};