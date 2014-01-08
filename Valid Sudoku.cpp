class Solution {
public:
    bool isValid(vector<vector<char> > &board, int x, int y, int len){
        char c = board[x][y];
        if(c == '.'){
            return true;
        }
        for(int i=0; i<len; i++){
            if(x!=i && board[i][y] == c){
                return false;
            }
        }
        for(int j=0; j<len; j++){
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
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = board.size();
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                if(!isValid(board, i, j, len)){
                    return false;
                }
            }
        }
        return true;
    }
};