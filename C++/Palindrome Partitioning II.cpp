//动态规划，判断回文也用动规，非常经典的题，状态转移方程很不错
class Solution {  
public:  
	//res[i] 区间[i,n]之间最小的cut数，n为字符串长度，则
	//res[i] = min(1+res[j+1], res[i] ) 若 i<=j <n，且s[i..j]是回文
	//因为，可以从j后面分割，j+1到n的之前分过了（子问题）
    int minCut(string s) {  
        int n = s.size();  
        vector<int > res(n+1);  
        vector<vector<bool> > p(n, vector<bool>(n, false));  
        for(int i = 0; i <= n; ++i) {  
            res[i] = n - i - 1; //比如res[0]开始应初始化为n-1次 
        } 
		//从后往前数
        for(int i = n - 1; i >=0; --i) {  
            for(int j = i; j < n; ++j) {  
                if(s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) { //判断回文
                    p[i][j] = true; //s[i..j]是回文
                    res[i] = min(res[i], res[j + 1] + 1);  
                }  
            }  
        }  
        return res[0];  
    }  
};