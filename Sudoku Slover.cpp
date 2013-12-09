class Solution {
private:
    bool isValid(vector<vector<char> > &board, int x, int y){
        char c = board[x][y];
        if(c == '.'){
            return true;
        }
        for(int i=0; i<9; i++){
            if(x!=i && board[i][y] == c){
                return false;
            }
        }
        for(int j=0; j<9; j++){
            if(y!=j && board[x][j] == c){
                return false;
            }
        }
        for(int i=(x/3)*3; i<(x/3+1)*3; i++){
            for(int j=(y/3)*3; j<(y/3+1)*3; j++){
                if((i!=x && j!=y) && board[i][j] == board[x][y]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool solveSudoku(vector<vector<char> > &board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    for(int k=1; k<=9; k++){
                        board[i][j] = '0' + k;
						//这一行是关键，用了DFS，如果没成功就回溯
                        if(isValid(board, i, j) && solveSudoku(board)){
                            return true;
                        }
						//回溯
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
};