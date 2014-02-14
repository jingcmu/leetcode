//思路：不知道搜索起点？以每个点为起点搜索，反正很快会剪枝的
//这里用的其实就是备忘录法，用了一个visited来记录是否已经访问过
class Solution {
private:
    int height;
    int width;
public:
    bool exist(vector<vector<char> > &board, string word) {
        height = board.size();
        if(!height) return false;
        width = board[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(search(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board, int x, int y, string &word, int index, vector<vector<bool>> &visited){
        if(index == word.length()) return true;

        if(x<0 || y<0 || x>=height || 
           y>=width || visited[x][y] ||
           board[x][y] != word[index] ) return false;  
		
        visited[x][y] = true;
        if(search(board, x+1, y, word, index+1, visited) ||
           search(board, x-1, y, word, index+1, visited) ||
           search(board, x, y+1, word, index+1, visited) ||
           search(board, x, y-1, word, index+1, visited) ) return true;
		
        visited[x][y] = false;
        return false;
    }
};