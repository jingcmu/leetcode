My solution:
//从后往前读，先把后面的空格丢掉
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s), len_last = 0;
        int cur = len-1;
        if(!len){
            return 0;
        }
        while(s[cur]==' ' && cur-->=0);
        while(s[cur]!=' ' && cur-->=0){
            len_last++;
        }
        return len_last;
    }
};

Second try:
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int size = strlen(s);
        int res = 0;
        while(s[size-1] == ' ') size--;
        while(size > 0 && s[size-1] != ' ') {
            res++;
            size--;
        }
        return res;
    }
};

Other solution:
//从前往后读, 实现比较猥琐，s++还是不++，非常绕
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int len = 0;
		while (*s) {
			if (*s++ != ' ') //如果没遇到空格len就++
				++len;
			else if (*s && *s != ' ')//如果遇到空格，再次遇到不是空格的len清零
				len = 0;
		}
		return len;
	}
};

//用STL
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		const string str(s);
		//从后往前找第一个字母
		auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
		//从最后一字母往前找第一个非字母
		auto last = find_if_not(first, str.rend(), ::isalpha);
		//计算两者差距
		return distance(first, last);
	}
};
