/*
字符串处理题很多都可以使用动态规划。
设状态为f(i,j)，表示T[0,j]在S[0,i]里出现的次数。首先，无论S[i]和T[j]是
否相等，若不使用S[i]，则f(i,j) = f(i-1,j)；若S[i]==T[j]，则可以使用S[i]，此时
f(i,j) = f(i-1,j) + f(i-1,j-1)，f(i-1,j)代表不使用S[i]，f(i-1,j-1)代表使用S[i]
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int lenS = S.length();
        int lenT = T.length();
        if(lenS < lenT) return 0;
        vector<vector<int> > res(lenS, vector<int>(lenT, 0));
        if(S[0] == T[0]) res[0][0] = 1;
		//初始化第一列，第一行都是0不需要额外初始化
        for(int i=1; i<lenS; i++){
            if(S[i] == T[0]){
                res[i][0] = res[i-1][0] + 1;
            }
            else{
				res[i][0] = res[i-1][0];
			}
        }
        for(int i=1; i<lenS; i++){
            for(int j=1; j<lenT; j++){
				//根据状态转移方程...
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

// 二维动规+ 滚动数组
// 时间复杂度O(m*n)，空间复杂度O(n)
class Solution {
public:
	int numDistinct(const string &S, const string &T) {
		vector<int> f(T.size() + 1);
		f[0] = 1;
		for (int i = 0; i < S.size(); ++i) {
			for (int j = T.size() - 1; j >= 0; --j) {
				f[j + 1] += S[i] == T[j] ? f[j] : 0;
			}
		}
		return f[T.size()];
	}
};