/*
这一题跟work ladder的区别是需要用一个map记录ladder的路径
这个map设置的很巧妙，key是string代表当前节点，
value是一个vector<string>用来记录从哪些节点可以到当前节点
*/
class Solution {
	public:
	vector<vector<string> > findLadders(string start, string end,
		const unordered_set<string> &dict) {
		unordered_set<string> visited; // 判重
		unordered_map<string, vector<string> > father; // 树
		unordered_set<string> current, next; // 当前层，下一层，用集合是为了去重
		bool found = false;
		current.insert(start);
		while (!current.empty() && !found) {
			// 先将本层全部置为已访问，防止同层之间互相指向
			for (auto word : current)
				visited.insert(word); 
			for (auto word : current) { //对当前层每个单词遍历
				for (size_t i = 0; i < word.size(); ++i) {
					string new_word = word;
					//替换字符，构造新字符串，判断是否在dict中
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == new_word[i]) continue;
						swap(c, new_word[i]);
						if (new_word == end) {
							found = true; //找到了, 不需要放到next队列了
							father[new_word].push_back(word);
							break;
						}
						if (visited.count(new_word) == 0
						&& (dict.count(new_word) > 0 || new_word == end)) {
							next.insert(new_word);
							father[new_word].push_back(word);
						}
						swap(c, new_word[i]); // restore
					}
				}
			}
			current.clear();
			swap(current, next);
		}
		vector<vector<string> > result;
		if (found) {
			vector<string> path;
			buildPath(father, path, start, end, result);
		}
		return result;
	}
	private:
	//用father构建路径
	//param: father保存每个节点的父节点队列，path是
	//result用来保存最终结果(从start到end的路径)，
	void buildPath(unordered_map<string, vector<string> > &father, vector<string> &path,
			 const string &start, const string &word, vector<vector<string> > &result )
	{
		path.push_back(word);
		if (word == start) {
			result.push_back(path); //结果放到result最后
			//结果是反的，所以要逆序
			reverse(result.back().begin(), result.back().end());
		} 
		else {
			for (auto f : father[word]) { //把节点的每个father推入队列
				buildPath(father, path, start, f, result);
			}
		}
		path.pop_back();
	}
};
