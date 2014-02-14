class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> rows(nRows);
        string solution = "";
        int size = s.size(), cur = 0, dir = 0;
		//快速终止条件
        if(nRows == 1 || nRows > size) {
            return s;
        }
        for(int i=0; i<size; i++) {
            rows[cur]+=s[i];
            if(dir == 0){ //0代表向下，1代表向上
                cur++;
                if(cur == nRows-1) {
                    dir = 1; //反转
                }
            }
            else{
                cur--;
                if(cur == 0){
                    dir = 0; //反转
                }
            }
        }
        for(int j=0; j<nRows; j++) {
            solution += rows[j];
        }
        return solution;
    }
};