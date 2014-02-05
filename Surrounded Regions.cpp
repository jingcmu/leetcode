/*
这题就是把所有被X围住的O换成X，O没有被X全围住的情况就是那一组O连接了边界，
只要把连接了边界的O全部先换成*（或其他字符），然后把剩余的O全部换成*，
最后再把*换回O即可
在把连接了边界的O全部先换成*这一步，用BFS宽搜
*/
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int height = board.size(), width;
        if(height == 0) return;
        width = board[0].size();
		//以两个竖边上的O为起点进行宽搜替换
        for(int i=0; i<height; i++){
            if(board[i][0] == 'O'){
                bfs(i, 0, board);
            } 
            if(board[i][width-1] == 'O'){
                bfs(i, width-1, board);
            }
        }
        //以上下两个横边上的O为起点进行宽搜替换
        for(int j=1; j<width-1; j++){
            if(board[0][j] == 'O'){
                bfs(0, j, board);
            }
            if(board[height-1][j] == 'O'){
                bfs(height-1, j, board);
            }
        }
        //把O换成X，*换成O
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
        visit(x, y, board, q); //访问处于边界上的点(起点)
        while(!q.empty()) {
            //从队列取出一个点，并且访问其上下左右四个点
            position cur = q.front(); 
            q.pop();
            visit(cur.x-1, cur.y, board, q);
            visit(cur.x, cur.y-1, board, q);
            visit(cur.x+1, cur.y, board, q);
            visit(cur.x, cur.y+1, board, q);
        }
    }
    //访问坐标为(x,y)的节点，如果是O，则替换成*，并放入队列
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