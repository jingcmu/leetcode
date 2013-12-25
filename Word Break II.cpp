class Solution {
public:
	//��word break������prev��¼����Щλ�ÿ��Էִʳ���
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		// ����Ϊn ���ַ�����n+1 ������
		vector<bool> f(s.length() + 1, false);
		// path[i][j] Ϊtrue����ʾs[j, i) ��һ���Ϸ����ʣ����Դ�j ���п�
		// ��һ��δ��
		vector<vector<bool> > prev(s.length() + 1, vector<bool>(s.length()));
		f[0] = true;
		for (size_t i = 1; i <= s.length(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					prev[i][j] = true;
				}
			}
		}
		vector<string> result;
		vector<string> path;
		gen_path(s, prev, s.length(), path, result);
		return result;
	}
private:
	// DFS ������������·��
	void gen_path(const string &s, const vector<vector<bool> > &prev,
		int cur, vector<string> &path, vector<string> &result) {
		if (cur == 0) {
			string tmp;
			for (auto iter = path.crbegin(); iter != path.crend(); ++iter){
				tmp += *iter + " ";
			}
			tmp.erase(tmp.end() - 1);
			result.push_back(tmp);
		}
		for (size_t i = 0; i < s.size(); ++i) {
			if (prev[i][cur]) {
				path.push_back(s.substr(i, cur - i));
				gen_path(s, prev, i, path, result);
				path.pop_back();
			}
		}
	}
};