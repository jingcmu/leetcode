class Solution {
public:
	//跟word break区别：用prev记录下哪些位置可以分词出来
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		// 长度为n 的字符串有n+1 个隔板
		vector<bool> f(s.length() + 1, false);
		// prev[i][j] 为true，表示s[j, i) 是一个合法单词，可以从j 处切开
		// 第一行未用
		vector<vector<bool> > prev(s.length() + 1, vector<bool>(s.length()));
		/*DP, 设状态为f(i)，表示字符串s从第0个到第i个字符之前那个位置是否可以分词，
		状态转移方程为：
		f(i) = any_of(f(j)&&s[j, i) 在 dict 中); 0 <= j < i
		*/
		f[0] = true; // 空字符串
		for (size_t i = 1; i <= s.length(); ++i) { //从第一个分隔到尾后元素
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true; //发现第i个位置前能分词仍然要试探其他的位置
					prev[i][j] = true; //从j到i前的位置是一个dict中的单词
				}
			}
		}
		vector<string> result;
		vector<string> path;
		gen_path(s, prev, s.length(), path, result);
		return result;
	}
private:
	// DFS 遍历树，生成路径
	void gen_path(const string &s, const vector<vector<bool> > &prev,
		int cur, vector<string> &path, vector<string> &result) {
		if (cur == 0) {
			string tmp;
			//push的时候是逆序的，现在再逆过来
			for (auto iter = path.crbegin(); iter != path.crend(); ++iter){
				tmp += *iter + " ";
			}
			tmp.erase(tmp.end() - 1);
			result.push_back(tmp);
		}
		for (size_t i = 0; i < s.size(); ++i) {
			if (prev[i][cur]) { //如果从s[cur, i)是一个dict中的单词
				path.push_back(s.substr(i, cur - i)); //把该单词入栈
				gen_path(s, prev, i, path, result); //对字符串剩余部分递归
				path.pop_back(); //还原现场
			}
		}
	}
};