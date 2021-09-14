/*
这题就是把所有被X围住的O换成X，O没有被X全围住的情况就是那一组O连接了边界，
只要把连接了边界的O全部先换成*（或其他字符），然后把剩余的O全部换成*，
最后再把*换回O即可
在把连接了边界的O全部先换成*这一步，用BFS宽搜
*/
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        h = board.size();
        if(h == 0) return;
        w = board[0].size();
        //以两个竖边上的O为起点进行宽搜替换
        for(int i=0; i<h; i++) {
            if(board[i][0] == 'O') {
                q.push(make_pair(i,0));
            }
            if(board[i][w-1] == 'O') {
                q.push(make_pair(i,w-1));
            }
        }
        //以上下两个横边上的O为起点进行宽搜替换
        for(int i=0; i<w; i++) {
            if(board[0][i] == 'O') {
                q.push(make_pair(0, i));
            }
            if(board[h-1][i] == 'O') {
                q.push(make_pair(h-1, i));
            }
        }
        bfs(board);
        //把O换成X，*换成O
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(board[i][j] == '*') {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    int h, w;
    queue<pair<int, int>> q;
    void bfs(vector<vector<char>> &board) {
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            // 替换成*
            board[p.first][p.second] = '*';
            visit(board, p.first+1, p.second);
            visit(board, p.first-1, p.second);
            visit(board, p.first, p.second+1);
            visit(board, p.first, p.second-1);
        }
    }
    //访问坐标为(x,y)的节点
    void visit(vector<vector<char>> &board, int y, int x) {
        if(x<0 || x>w-1 || y<0 || y>h-1 || board[y][x] != 'O') {
            return;
        }
        // 如果为0，放入队列
        q.push(make_pair(y, x));
    }
};
