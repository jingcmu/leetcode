My solution:
//�Ӻ���ǰ�����ȰѺ���Ŀո񶪵�
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
//��ǰ�����, ʵ�ֱȽ������s++���ǲ�++���ǳ���
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int len = 0;
		while (*s) {
			if (*s++ != ' ') //���û�����ո�len��++
				++len;
			else if (*s && *s != ' ')//��������ո��ٴ��������ǿո��len����
				len = 0;
		}
		return len;
	}
};

//��STL
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		const string str(s);
		//�Ӻ���ǰ�ҵ�һ����ĸ
		auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
		//�����һ��ĸ��ǰ�ҵ�һ������ĸ
		auto last = find_if_not(first, str.rend(), ::isalpha);
		//�������߲��
		return distance(first, last);
	}
};
