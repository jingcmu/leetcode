class Solution {
public:
int ladderLength(string start, string end,
	const unordered_set<string> &dict) {
		if (start.size() != end.size()) return 0;
		if (start.empty() || end.empty()) return 0;
		queue<string> next, current; // ��ǰ�㣬��һ��
		unordered_set<string> visited; // ����
		int level = 0; // ���
		bool found = false;
		current.push(start);
		while (!current.empty() && !found) {
			++level;
			while (!current.empty() && !found) {
				const string str(current.front()); 
				current.pop();
				for (size_t i = 0; i < str.size(); ++i) {
					string new_word(str);
					for (char c = 'a'; c <= 'z'; c++) {
						if (c == new_word[i]) continue;
						swap(c, new_word[i]);
						if (new_word == end) {
							found = true; //�ҵ���
							break;
						}
						if (dict.count(new_word) > 0
							&& !visited.count(new_word)) {
							next.push(new_word);
							visited.insert(new_word);
						}
						swap(c, new_word[i]); // �ָ��õ���
					}
				}
			}
			swap(next, current); //!!! ������������
		}
		if (found) return level+1;
		else return 0;
	}
};