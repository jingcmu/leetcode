//O(m + n) �ռ�ķ����ܼ򵥣������������飬��¼ÿ�к�ÿ���Ƿ����0��
//��Ҫ�����ռ䣬���Ը��õ�һ�к͵�һ�С�
O(m+n)�ռ�ķ���:
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		const size_t m = matrix.size();
		const size_t n = matrix[0].size();
		vector<bool> row(m, false); // ��Ǹ����Ƿ����0
		vector<bool> col(n, false); // ��Ǹ����Ƿ����0
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

O(1)�ռ�ķ���:
˼·���õ�һ�м�¼ÿһ�У�����һ���⣩�ǲ���Ӧ�����㣬
�õ�һ�м�¼ÿһ�У�����һ���⣩�ǲ���Ӧ������
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
		//���жϵ�һ�е�һ���Ƿ�Ӧ����
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
		//������һ��ֻ࣬�ǽ����¼�ط���ͬ
        for(int i=1; i<height; i++){
            for(int j=1; j<width; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
		//���濪ʼ����
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