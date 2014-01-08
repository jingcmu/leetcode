class Solution {
public:
    string convert(string s, int nRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.  
        vector<string> rows;
        string solution;
        int size = s.size(), cur=0, dir = 0;
        if(nRows == 1 || nRows > size){
            return s;
        }
        rows.resize(nRows);
        for(int i=0; i<size; i++){
            rows[cur]+=s[i];
            if(dir == 0){
                cur++;
                if(cur == nRows-1){
                    dir = 1;
                }
            }
            else{
                cur--;
                if(cur == 0){
                    dir = 0;
                }
            }
        }
        solution = rows[0];
        for(int j=1; j<nRows; j++){
            solution+=rows[j];
        }
        return solution;
    }
};