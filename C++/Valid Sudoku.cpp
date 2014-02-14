/*
第一种解法：
对每个放置的元素检查横竖框
*/
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

/*
第二种解法：
对每个横竖框检查里面的元素，显然这种方法效率高
*/
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool used[9];
		for (int i = 0; i < 9; ++i) {
		fill(used, used + 9, false); 
		for (int j = 0; j < 9; ++j) // 检查行
			if (!check(board[i][j], used))
				return false;
		fill(used, used + 9, false);
		for (int j = 0; j < 9; ++j) // 检查列
			if (!check(board[j][i], used))
				return false;
		}
		for (int r = 0; r < 3; ++r) // 检查9 个子格子
		for (int c = 0; c < 3; ++c) {
			fill(used, used + 9, false);
			for (int i = r * 3; i < r * 3 + 3; ++i)
			for (int j = c * 3; j < c * 3 + 3; ++j)
			if (!check(board[i][j], used))
			return false;
		}
		return true;
	}
	
	//检查横竖或框中的一个位置，顺便把已经出现过的数字标记下
	bool check(char ch, bool used[9]) {
		if (ch == '.') return true;
		if (used[ch - '1']) return false;
		used[ch - '1'] = true;
		return true;
	}
};