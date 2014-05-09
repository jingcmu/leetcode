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

//DFS Solution
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if((s1 == s3 && s2.length() == 0) || (s2 == s3 && s1.length() == 0)) return true;
        if((s1 != s3 && s2.length() == 0) || (s2 != s3 && s1.length() == 0)) return false;
        if(s1[0] == s3[0] && isInterleave(s1.substr(1), s2, s3.substr(1))) {
            return true;
        }
        else if(s2[0] == s3[0] && isInterleave(s1, s2.substr(1), s3.substr(1))) {
            return true;
        }
        return false;
    }
};

//third try
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len3 != len1+len2) return false;
        if(len3 == len1) return s3 == s1;
        if(len3 == len2) return s3 == s2;
        vector<vector<bool>> res(len1+1, vector<bool>(len2+1, false));
        bool flag = true;
        for(int i=1; i<=len1; i++) {
            if(flag == true && s1[i-1] == s3[i-1]) {
                res[i][0] = true;
            }
            else {
                flag = false;
                res[i][0] = false;
            }
        }
        flag = true;
        for(int i=1; i<=len2; i++) {
            if(flag == true && s2[i-1] == s3[i-1]) {
                res[0][i] = true;
            }
            else {
                flag = false;
                res[0][i] = false;
            }
        }
        for(int i=1; i<=len1; i++) {
            for(int j=1; j<=len2; j++) {
                res[i][j] = (res[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                            (res[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
        return res[len1][len2];
    }
};