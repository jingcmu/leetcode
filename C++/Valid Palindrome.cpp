My solution:
双指针的思想真是无处不在啊，两头往中间遍历貌似可以ko掉很多题
不过这一题比USACO上的类似的一道题简单
class Solution {
public:
    bool isPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
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

纯STL实现方法
isalnum用来判断是否字母和数字，prev返回迭代器前的位置，tolower转换小写字母
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