/*
Ūһ��ջ��vectorģ�⣩������������������ջ��
���������žͰѶ�Ӧ�������ų�ջ�����ջΪ��Ϊ�ռ���
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
			//��Ϊ��������֮��Ĳ����3����ASCII���
            if(diff > 0 && diff < 3) {
                v.pop_back(); //����Ƕ�Ӧ�������ţ������ų�ջ
            }
            else {
                v.push_back(s[i]); //������ջ
            }
        }
		return v.size() == 0;
    }
};

Second try:

class Solution {
public:
    bool isValid(string s) {
       stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if(s[i] == ')' && (!st.empty() && st.top() == '(')) {
                    st.pop();
                    continue;
                }
                if(s[i] == '}' && (!st.empty() &&st.top() == '{')) {
                    st.pop();
                    continue;
                }
                if(s[i] == ']' && (!st.empty() &&st.top() == '[')) {
                    st.pop();
                    continue;
                }
                return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};