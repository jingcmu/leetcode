//DFS解法+备忘录
class Solution {
private:
    map<int, bool> m;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
		//看看s本身在不在dict里面
        if(dict.find(s) != dict.end()) return true;
        
		//对每个位置尝试进行分割
        for(int i=1; i<len; i++) {
            if(dict.find(s.substr(0,i)) != dict.end()) { //如果某位置之前的子串在dict中，则判断剩余的是否能划分 
                if(!m[i] && wordBreak(s.substr(i,len-i), dict)) {
                    return true;
                }
                else {
                    m[i] = true; //用备忘录记录下，这个位置就不必重复检验了
                }
            }
        }
        return false;
    }
};

//DP解法
/*设状态为f(i)，表示s[0,i] 是否可以分词，则状态转移方程为
f(i) = any_of(f(j)&&s[j + 1, i] 在 dict 中); 0 <= j < i
*/
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		// 长度为n 的字符串有n+1 个隔板
		vector<bool> f(s.size() + 1, false);
		f[0] = true; // 空字符串
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					break;
				}
			}
		}
		return f[s.size()];
	}
};