// 给出一个字符串，重新排列其字母，使其没有两个相邻字母是相同的
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string merge(string s1, string s2) {
	string s = "";
	int len1 = s1.length(), len2 = s2.length();
	for (int i = 0; i < min(len1, len2); ++i) {
		s += s1[i];
		s += s2[i];
	}
	if (len1 == len2) return s;
	return len1 > len2 ? s + s1[len1 - 1] : s + s2[len2 - 1];
}

bool ispossible(string& s) {
	char c = s[0];
	int max_len = 1, len;
	for (int i = 1; i < s.length(); ++i) {
		len = 1;
		while (i < s.length() && s[i] == s[i - 1]) {
			++len;
			c = s[i++];
		}
		if (max_len < len) {
			c = s[i - 1];
			max_len = len;
		}
	}
	return max_len <= ((s.length() + 1) / 2);
}

void reorder(string& s) {
	int len = s.length();
	if (s[(len + 1) / 2] != s[(len + 1) / 2 - 1])
		return;
	else {
		for (int i = (len + 1) / 2, j = 0; i < len && s[i] == s[(len + 1) / 2 - 1]; ++i)
			swap(s[j++], s[i]);
	}
}

bool shuffle(string& s){
	int len = s.length();
	if (!len) return false;
	if (len == 1) return true;
	sort(s.begin(), s.end());
	if (!ispossible(s)) return false; // more than 1/2 same char
	else {
		reorder(s);
		s = merge(s.substr(0, len / 2 + 1), s.substr(len / 2 + 1));
		return true;
	}
}

int main() {
	string s = "abbbbcd";
	if (shuffle(s)) {
		cout << s << endl;
	}
	else cout << "Not possible" << endl;
}
