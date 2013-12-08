class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        if(len != s2.length()) return false;
        bool res[len+1][len][len];
        memset(res, false, sizeof(bool)*(len+1)*len*len);
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                res[1][i][j] = s1[i]==s2[j];
            }
        }
        //l stand for length
        for(int l=2; l<=len; l++){
            for(int i=0; i<=len-l; i++){  //注意等于号
                for(int j=0; j<=len-l; j++){
                    for(int divlen=1; divlen<l && !res[l][i][j]; divlen++){
                        if((res[divlen][i][j] && res[l-divlen][i+divlen][j+divlen]) 
                            || (res[divlen][i][j+l-divlen] && res[l-divlen][i+divlen][j])){
                            res[l][i][j] = true;
                            break;   //有一次true就可以了
                        }
                    }
                }
            }
        }
        return res[len][0][0];
    }
};