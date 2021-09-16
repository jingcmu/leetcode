My solution:
//��ά��̬�滮,ֱ����grid������,ȱ����grid���޸���
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

//��̬�滮+��������,���޸�grid
//����֮�������ﲻ��Ҫ�����һ�к͵�һ�е�ֵ
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		const int m = grid.size();
		const int n = grid[0].size();
		int f[n];
		fill(f, f+n, INT_MAX); // ��ʼֵ��INT_MAX����Ϊ��������min ������
		f[0] = 0;
		for (int i = 0; i < m; i++) {
			f[0] += grid[i][0];
			for (int j = 1; j < n; j++) {
				// ��ߵ�f[j]����ʾ���º��f[j]���빫ʽ�е�f[i][j] ��Ӧ
				// �ұߵ�f[j]����ʾ�ϵ�f[j]���빫ʽ�е�f[i-1][j] ��Ӧ
				f[j] = min(f[j - 1], f[j]) + grid[i][j];
			}
		}
		return f[n - 1];
	}
};