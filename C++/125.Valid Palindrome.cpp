My solution:
˫ָ���˼�������޴����ڰ�����ͷ���м����ò�ƿ���ko���ܶ���
������һ���USACO�ϵ����Ƶ�һ�����
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        bool isPalin = true;
        int head = 0, tail = len-1;
        if(!len){
            return true;
        }
        while(head<tail){
            if(!(isalpha(s[head]) || isdigit(s[head]))){
                head++;
                continue;
            }
            if(!(isalpha(s[tail]) || isdigit(s[tail]))){
                tail--;
                continue;
            }
            if(s[head] != s[tail] && abs(s[head]-s[tail]) != 32){
                return false;
            }
            head++;
            tail--;
        }
        return isPalin;
    }
};

��STLʵ�ַ���
isalnum�����ж��Ƿ���ĸ�����֣�prev���ص�����ǰ��λ�ã�tolowerת��Сд��ĸ
class Solution {
public:
	bool isPalindrome(string s) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left = s.begin(), right = prev(s.end());
		while (left < right) {
			if (!::isalnum(*left)) ++left;
			else if (!::isalnum(*right)) --right;
			else if (*left++ != *right--) return false;
		}
		return true;
	}
};