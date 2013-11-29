class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int height = board.size(), width;
        if(height == 0) return;
        width = board[0].size();
        for(int i=0; i<height; i++){
            if(board[i][0] == 'O'){
                bfs(i, 0, board);
            } 
            if(board[i][width-1] == 'O'){
                bfs(i, width-1, board);
            }
        }
        
        for(int j=1; j<width-1; j++){
            if(board[0][j] == 'O'){
                bfs(0, j, board);
            }
            if(board[height-1][j] == 'O'){
                bfs(height-1, j, board);
            }
        }
        
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
            }
        }
    }
private:
    struct position{
        int x;
        int y;
    };
    
    void bfs(int x, int y, vector<vector<char>> &board){
        queue<position> q;
        visit(x, y, board, q);
        while(!q.empty()) {
            //fetch one position from queue
            position cur = q.front(); 
            q.pop();
            visit(cur.x-1, cur.y, board, q);
            visit(cur.x, cur.y-1, board, q);
            visit(cur.x+1, cur.y, board, q);
            visit(cur.x, cur.y+1, board, q);
        }
    }
    
    void visit(int x, int y, vector<vector<char>> &board, queue<position> &q){
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == 'X'){
            return;
        }
        if(board[x][y] == 'O'){
            position p;
            p.x = x;
            p.y = y;
            board[x][y] = '*';
            q.push(p);
        }
    }
};