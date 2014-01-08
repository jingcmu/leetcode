class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case. 
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1+len2 != len3){
            return false;
        }
        vector<vector<bool> > isReachable;
        vector<bool> v;
        v.resize(len1+1);
        for(int i=0; i<=len2; i++){
            isReachable.push_back(v);
        }
        isReachable[0][0] = true;
        for(int i=1; i<=len1; i++){
            isReachable[0][i] = (isReachable[0][i-1] && s3[i-1]==s1[i-1])? true:false;
        }
        for(int i=1; i<=len2; i++){
            isReachable[i][0] = (isReachable[i-1][0] && s3[i-1]==s2[i-1])? true:false;
        }
        for(int i=1; i<=len2; i++){             //line
            for(int j=1; j<=len1; j++){         //col
                isReachable[i][j] = ( (isReachable[i-1][j] && s3[i+j-1]==s2[i-1]) ||
                                    (isReachable[i][j-1] && s3[i+j-1]==s1[j-1]))? true:false;
            }
        }
        return isReachable[len2][len1];
    }
};