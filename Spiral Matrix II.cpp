class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int nSquare = n*n, num = 0, dir = 0;
        int pos_x = 0, pos_y = 0;
        vector<vector<int> > v_ret;
        v_ret.resize(n);
        for(int i=0; i<n; i++){
            v_ret[i].resize(n);
        }
        while(num++ < nSquare){
            v_ret[pos_x][pos_y] = num;
            switch(dir){
                case 0: 
                pos_y++;
                if(pos_y >= n-1 || v_ret[pos_x][pos_y+1]){
                    dir++;
                }
                break;
                case 1:
                pos_x++;
                if(pos_x >= n-1 || v_ret[pos_x+1][pos_y]){
                    dir++;
                }
                break;
                case 2:
                pos_y--;
                if(pos_y <=0 || v_ret[pos_x][pos_y-1]){
                    dir++;
                }
                break;
                case 3:
                pos_x--;
                if(pos_x <=0 || v_ret[pos_x-1][pos_y]){
                    dir = 0;
                }
                break;
            }
        }
        return v_ret;
    }
};