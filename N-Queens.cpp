//
class Solution {
private:
    vector<vector<string> > ret;
public:
    bool valid(vector<vector<int> > &maxtrix, int row, int col, int n){
        int i, j;
		//检查有没有同列的（只要检查之前行即可）
        for(i=0; i<row; i++)
            if(maxtrix[i][col])
                return false;
        //检查左上对角
        i = row; j = col;
        while(i && j){
            if(maxtrix[--i][--j])
                return false;
		//检查右上角
        i = row; j = col;
        while(i && j<n-1){
            if(maxtrix[--i][++j]){
                return false;
        return true;
    }

	//深度优先，逐行逐列试探，行是递归往下，列是循环试探
	//参数：棋盘大小n，记录当前放置信息的matrix，当前操作的行row
    void solveNQueens(int n, vector<vector<int> > &matrix, int row) {
        vector<string> v(n);
        string str;
		//DFS的终止条件
        if(line == n){ //如果已经成功，就把1和0翻译成Q和.
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
		//DFS核心，对当前行的每一列进行试探，如果合法，则往下一行递归
        for(int j=0; j<n; j++){
            matrix[row].clear();
            if(valid(matrix, row, j, n)){ //如果当前列合法
                matrix[line][j] = 1; //当前行、列置为1
                solveNQueens(n, matrix, row+1); //递归下一层
                matrix[row][j] = 0;  //清除当前行、列
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