//O(m + n) 空间的方法很简单，设置两个数组，记录每行和每列是否存在0。
//想要常数空间，可以复用第一行和第一列。
O(m+n)空间的方法:
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();
		vector<bool> row(m, false); // 标记该行是否存在0
		vector<bool> col(n, false); // 标记该列是否存在0
		for (size_t i = 0; i < m; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					row[i] = col[j] = true;
				}
			}
		}
		for (size_t i = 0; i < m; ++i) {
			if (row[i])
				fill(&matrix[i][0], &matrix[i][0] + n, 0);
		}
		for (size_t j = 0; j < n; ++j) {
			if (col[j]) {
				for (size_t i = 0; i < m; ++i) {
					matrix[i][j] = 0;
				}
			}
		}
	}
};

O(1)空间的方法:
思路：用第一行记录每一列（除第一列外）是不是应该置零，
用第一列记录每一行（除第一行外）是不是应该置零
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool first_line = false, first_column = false;
        int height = matrix.size();
        if(!height){
            return;
        }
        int width = matrix[0].size();
		//先判断第一行第一列是否应置零
        for(int i=0; i<width; i++){
            if(!matrix[0][i]){
                first_line = true;
                break;
            }
        }
        for(int i=0; i<height; i++){
            if(!matrix[i][0]){
                first_column = true;
                break;
            }
        }
		//跟方法一差不多，只是结果记录地方不同
        for(int i=1; i<height; i++){
            for(int j=1; j<width; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
		//下面开始置零
        for(int i=1; i<height; i++){            
            for(int j=1; j<width; j++){
				if(!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;
            }
        }
        
        if(first_line){
            for(int j=0; j<width; j++){
                matrix[0][j] = 0;
            }
        }
        if(first_column){
            for(int i=0; i<height; i++){
                matrix[i][0] = 0;
            }
        }
        return;
    }
};