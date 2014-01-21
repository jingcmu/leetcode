/*
弄一个栈（vector模拟），把遇到的左括号入栈，
遇到右括号就把对应的左括号出栈，最后看栈为不为空即可
*/
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        int len = s.length();
        if(len == 0) return true;
        for(int i=0; i<s.length(); i++) {
            int diff = 0; 
            if(v.size()) {
                diff = s[i] - v[v.size()-1];
            }
			//因为左右括号之间的差不大于3（看ASCII码表）
            if(diff > 0 && diff < 3) {
                v.pop_back(); //如果是对应的右括号，左括号出栈
            }
            else {
                v.push_back(s[i]); //否则，入栈
            }
        }
		return v.size() == 0;
    }
};