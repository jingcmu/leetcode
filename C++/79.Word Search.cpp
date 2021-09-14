//思路：不知道搜索起点？以每个点为起点搜索，反正很快会剪枝的
//这里用的其实就是备忘录法，用了一个visited来记录是否已经访问过
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(search(board, i, j, m, n, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>> &board, int x, int y, int m, int n,
                string &word, int index, vector<vector<bool>> &visited){
        if(index == word.length()) return true;
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        if(x<0 || y<0 || x>=m || y>=n || visited[x][y] || board[x][y] != word[index])
            return false;  
		
        visited[x][y] = true;
        for (auto dir : dirs) {
            if(search(board,x+dir.first,y+dir.second,m,n,word,index+1,visited))
                return true;
        }
        visited[x][y] = false;
        return false;
    }
};
