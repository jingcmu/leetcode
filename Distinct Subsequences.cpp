class Solution {
public:
    int numDistinct(string S, string T) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int lenS = S.length();
        int lenT = T.length();
        if(lenS < lenT) return 0;
        vector<vector<int> > res;
        res.resize(lenS);
        for(int i=0; i<lenS; i++){
            res[i].resize(lenT);
        }
        if(S[0] == T[0]) res[0][0] = 1;
        for(int i=1; i<lenS; i++){
            if(S[i] == T[0]){
                res[i][0] = res[i-1][0] + 1;
            }
            else{
				res[i][0] = res[i-1][0];
			}
        }
        for(int i=1; i<lenT; i++){
            res[0][i] = 0;
        }
        for(int i=1; i<lenS; i++){
            for(int j=1; j<lenT; j++){
                if(S[i] == T[j]){
                    res[i][j] = res[i-1][j] + res[i-1][j-1];
                }
                else{
                    res[i][j] = res[i-1][j];
                }
            }
        }
        return res[lenS-1][lenT-1];
    }
};