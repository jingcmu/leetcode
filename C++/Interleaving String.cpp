/*
这题有点像unique path II那题，可以用动态规划或者DFS来做
动态规划的方法状态转移方程为：
isReachable[i][j] = ( (isReachable[i-1][j] && s3[i+j-1]==s2[i-1]) ||
                      (isReachable[i][j-1] && s3[i+j-1]==s1[j-1]))
isReachable下标没减一，s1、s2、s3下标减一是因为isReachable下标是0 0的时候代表没走，
而字符串下标是从0开始算的
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
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