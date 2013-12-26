My naive solution:
//没想到原地转置的办法,用了额外的空间
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		// Note: The Solution object is instantiated only once and is reused by each test case.
		vector<vector<int> > matrix_r;
		int n = matrix.size();
		matrix_r.resize(n);
		for(int i=0; i<n; i++){
			vector<int> v = matrix[n-i-1];
			for(int j=0; j<n; j++){
				matrix_r[j].push_back(v[j]);
			}
		}
		for(int i=0; i<n; i++){
			matrix[i] = matrix_r[i];
		}
		return;
	}
};

Better solutions:
Solution 1:
//沿副对角线反转+沿水平轴反转 
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n; ++i) // 沿着副对角线反转
			for (int j = 0; j < n - i; ++j)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		for (int i = 0; i < n / 2; ++i) // 沿着水平中线反转
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
	}
};

Solution 2:
//沿水平轴反转+沿主对角线反转
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		const int n = matrix.size();
		for (int i = 0; i < n / 2; ++i) // 沿着水平中线反转
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
		for (int i = 0; i < n; ++i) // 沿着主对角线反转
			for (int j = i + 1; j < n; ++j)
				swap(matrix[i][j], matrix[j][i]);
	}
};