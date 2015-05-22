/*
不要去对每个单词查词典里是否有距离为1的单词
而是要去查与该单词距离为1的单词是否在词典中

经典BFS，current是当前层队列，next是下一层队列
稍微修改了写法，感觉比戴方勤版的好理解一点点
*/
class Solution {
public:
int ladderLength(string start, string end,
	const unordered_set<string> &dict) {
		if (start.size() != end.size()) return 0;
		if (start.empty() || end.empty()) return 0;
		queue<string> current, next; // 当前层，下一层
		unordered_set<string> visited; // 判重
		int level = 0; // 层次
		bool found = false;
		current.push(start);
		while (true) { //不断对每层遍历
			++level;
			while (!current.empty() && !found) { //对当前队列的所有单词遍历
				const string str(current.front()); //取出队列头
				current.pop();
				for (size_t i = 0; i < str.size(); ++i) {
					string new_word(str);
					//通过改变一个字符，得到一个新的字符串
					for (char c = 'a'; c <= 'z'; c++) {
						if (c == new_word[i]) continue;
						swap(c, new_word[i]); //交换一个不同的字符
						if (new_word == end) {
							found = true; //找到了
							break;
						}
						if (dict.count(new_word) > 0 //如果字典里有这个单词
							&& !visited.count(new_word)) { //而且这个单词之前没访问过
							next.push(new_word); //把该单词push到next队列
							visited.insert(new_word); //标记为访问过
						}
						swap(c, new_word[i]); // 恢复该单词
					}
				}
			}
			if(!next.empty() && !found)
				swap(next, current); //!!! 交换两个队列
			else break;
		}
		if (found) return level+1;
		else return 0;
	}
};
