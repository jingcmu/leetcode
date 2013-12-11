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
                if(search(board, i, j, word, 0, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board, int x, int y, string &word, int index, vector<vector<bool>> &visited){
        if(index == word.length()){
            return true;
        }
        if(x<0 || y<0 || x>=height || y>=width ||
            visited[x][y] ||
            board[x][y] != word[index] 
            ){
            return false;
        }
        visited[x][y] = true;
        if(search(board, x+1, y, word, index+1, visited) ||
           search(board, x-1, y, word, index+1, visited) ||
           search(board, x, y+1, word, index+1, visited) ||
           search(board, x, y-1, word, index+1, visited) 
           ){
            return true;
        }
        visited[x][y] = false;
        return false;
    }
};