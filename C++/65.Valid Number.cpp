//ϸ���⣬��Ҫ��һЩ������� ��.��e��λ�ðڷ�
class Solution {
public:
    bool isNumber(const char *s) {
        int len, i;
        bool NoPoint = true;
        bool NoE = true;
        bool numeric = false;
        while(s && s[0] == ' ') s++; //ȥ��ǰ��Ŀո�
        if(s && (s[0] == '+' || s[0] == '-')) s++; //����з���λ��ȥ��
        i = len = strlen(s);
        while(s[--i] == ' ') len--; //ȥ������Ŀո�
        if(len <= 0 || s[0] == 'E' || s[0] == 'e') return false; //��Щ���ͳͳ����false
        if(len == 1 && s[0] == '.') return false; //������������ǿ��Ե�,���ǲ���ֻ��һ����
        for(i=0; i<len; i++){
            if(s[i] == '.'){ //�����˵�Ҫȷ������һ����
                if(NoPoint) {
                    NoPoint = false;
                    continue;
                }
                else return false;
            }
            if((s[i] == 'E' || s[i] == 'e')) {
                if(NoE && numeric) {
                    NoE = false;
                    NoPoint = false; //����e֮��Ͳ����ٳ���.��
                    if(s[i+1] == '+' || s[i+1] == '-') i++;
                    if(i+1 >= len) return false;
                    continue;
                }
                return false;
            }
            if(s[i] < 48 || s[i] > 57) return false;
            else numeric = true;
        }
        return true;
    }
};

//͵��������
class Solution {
public:
	bool isNumber (char const* s) {
		char* endptr;
		strtod (s, &endptr);
		if (endptr == s) return false; //"  "
		for (; *endptr; ++endptr)
			if (!isspace (*endptr)) return false;
		return true;
	}
};