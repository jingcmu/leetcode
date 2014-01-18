/*
用dir代表方向，0是往右，1是往下，2是往左，3是往上
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int nSquare = n*n, num = 0, dir = 0;
        int pos_x = 0, pos_y = 0;
        vector<vector<int> > v_ret(n,vector<int>(n));
        while(num++ < nSquare){
            v_ret[pos_x][pos_y] = num;
			if(dir == 0) {
				pos_y++;
                if(pos_y >= n-1 || v_ret[pos_x][pos_y+1]) dir++;
			}
			else if(dir == 1) {
				pos_x++;
                if(pos_x >= n-1 || v_ret[pos_x+1][pos_y]) dir++;
			}
			else if(dir == 2) {
				pos_y--;
                if(pos_y <= 0 || v_ret[pos_x][pos_y-1]) dir++;
			}
			else if(dir == 3) {
				pos_x--;
                if(pos_x <= 0 || v_ret[pos_x-1][pos_y]) dir = 0;
			}
		}
        return v_ret;
    }
};