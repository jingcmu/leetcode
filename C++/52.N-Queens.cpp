//����һ��
//�ö�άvector��¼���̷������
class Solution {
private:
    vector<vector<string> > ret;
public:
    bool valid(vector<vector<int> > &maxtrix, int row, int col, int n){
        int i, j;
		//�����û��ͬ�еģ�ֻҪ���֮ǰ�м��ɣ�
        for(i=0; i<row; i++)
            if(maxtrix[i][col])
                return false;
        //������϶Խ�
        i = row; j = col;
        while(i && j){
            if(maxtrix[--i][--j])
                return false;
		//������Ͻ�
        i = row; j = col;
        while(i && j<n-1){
            if(maxtrix[--i][++j]){
                return false;
        return true;
    }

	//������ȣ�����������̽�����ǵݹ����£�����ѭ����̽
	//���������̴�Сn����¼��ǰ������Ϣ��matrix����ǰ��������row
    void solveNQueens(int n, vector<vector<int> > &matrix, int row) {
        vector<string> v(n);
        string str;
		//DFS����ֹ����
        if(line == n){ //����Ѿ��ɹ����Ͱ�1��0�����Q��.
            for(int i=0; i<n; i++){
                str = "";
                for(int j=0; j<n; j++){
					str += (matrix[i][j] == 1? 'Q':'.');
                }
                v[i] = str;
            }
            ret.push_back(v);
			return;
        }
		//DFS���ģ��Ե�ǰ�е�ÿһ�н�����̽������Ϸ���������һ�еݹ�
        for(int j=0; j<n; j++){
            matrix[row].clear();
            if(valid(matrix, row, j, n)){ //�����ǰ�кϷ�
                matrix[line][j] = 1; //��ǰ�С�����Ϊ1
                solveNQueens(n, matrix, row+1); //�ݹ���һ��
                matrix[row][j] = 0;  //�����ǰ�С���
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        ret.clear();
        solveNQueens(n, matrix, 0);
        return ret;
    }
};

//��������
//��һάvector��¼���̷������
class Solution {
private:
	vector<vector<string> > ret;
public:
	//��������ǰ��row����¼ÿ�з����кŵ�����colArray
    bool check(int row, vector<int> &colArray) {  
		//����֮ǰ�еķ����������鵱ǰ
        for (int i = 0; i < row; ++i) {  
            int diff = abs(colArray[i] - colArray[row]); //diff��¼�кŲ�
            if (diff == 0 || diff == row - i) {          // int a row or line  
                return false;  
            }  
        }  
        return true;  
    }  
  
    void placeQueens(int row, int n, vector<int> &colArray) {
		vector<string> v(n);
        string str;
        if (row == n) {  
            for(int i=0; i<n; i++){
                str = "";
                for(int j=0; j<n; j++){
					str += (j == colArray[i]? 'Q':'.');
                }
                v[i] = str;
            }
            ret.push_back(v);
            return;  
        }  
          
        for (int col = 0; col < n; ++col) {  
            colArray[row] = col;  //����ÿ��
            if (check(row, colArray)){ //����Ϸ������µݹ�
                placeQueens(row+1, n, colArray);  
            }  
        }  
    }  
      
    vector<vector<string> > solveNQueens(int n) {  
        vector<int> colArray(n);             
        placeQueens(0, n, colArray);            
        return ret;  
    } 
};

//better solution
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, n, 0);
        return res;
    }
    
private:
    vector<vector<string>> res;
    void dfs(vector<string> &board,int n, int cur_row) {
        if(cur_row == n) {
            res.push_back(board);
            return;
        }
        for(int i=0; i<n; i++) {
            if(valid(board, i, cur_row, n)) {
                board[cur_row][i] = 'Q';
                dfs(board, n, cur_row+1);
                board[cur_row][i] = '.';   
            }
        }
    }
    
    bool valid(vector<string> &board, int x, int y, int n) {
        for(int i=0; i<y; i++) {
            if(board[i][x] == 'Q') return false;
        }
        for(int i=x+1,j=y-1; i<n&&j>=0; i++,j--) {
            if(board[j][i] == 'Q') return false;
        }
        for(int i=x-1,j=y-1; i>=0&&j>=0; i--,j--) {
            if(board[j][i] == 'Q') return false;
        }
        return true;
    }
};