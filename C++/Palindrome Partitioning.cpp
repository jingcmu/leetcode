//直接上最好的方法吧
//因为这个题目要求对整个字符串进行各种划分，所以最好能够得到从任意i到j位置是否为回文的一个表
//所以，上来先调用setIsPalin得到这个表
//tmp.push_back(s.substr(start, end-start+1))这句放的位置很好，如果放在循环里面，
//则push进去还要pop出来，太麻烦
class Solution {
    vector<vector<string>> result;
public:
    void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--) //必须从N-2循环到0
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
    
    void part(int start, int end, vector<string> tmp, string &s, vector<vector<bool>> &isPalin, int N){
        tmp.push_back(s.substr(start, end-start+1)); //push放在这里很好，因为是拷贝，所以不会影响原值
        if(end == N-1){ //如果已经对字符串遍历完了，则记录
            result.push_back(tmp); 
            return;
        }
        for(int i = end+1; i < N; i++){
            if(isPalin[end+1][i]){
                part(end+1, i, tmp, s, isPalin);
            }
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        int N = s.size();
        vector<vector<bool>> isPalin(N, vector<bool>(N, true));
        setIsPalin(s, isPalin, N);
        vector<string> tmp;
        for(int i = 0; i < N; i++){
            if(isPalin[0][i]){ //如果从0到i是回文，则对余下字符串判断是否能划分
                part(0, i, tmp, s, isPalin, N);
            }
        }
        return result;
    }
};

其中，
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--)
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
绝不可以写成：
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = 0; i < N-1; i++)
            for(int j = i+1; j < N; j++)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
但是可以写成：
	void setIsPalin(string s, vector<vector<bool>> &f, int N){
        for(int i = N-2; i >= 0; i--)
            for(int j = N-1; j >= i+1; j--)
                f[i][j] = s[i] == s[j] && f[i+1][j-1];
    }
为什么？
	想一下，如果要计算f[1][6]必须要知道f[2][5]，
	f[2][5]的计算要知道f[3][4]，所以i是从后往前倒着求才行，
	j的话没关系，本行之内没有依赖关系
