//��Climbing Stairs�����ƣ��������һЩ�ж��߼�
class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> v;
        v.resize(len+1);
        if(len == 0 || s[0] == '0'){
            return 0;
        }
        v[0] = v[1] = 1;
        for(int i=2; i<=len; i++){
            if(s[i-1] == '0') { //�����ǰ���ַ���0���������10����20���н�
                if(s[i-2]-'0' <= 2 && s[i-2]-'0' > 0) {
                    v[i] = v[i-2]; //�н⣬����ֻ����2����һ���
                }
                else {
                    return 0; //�����޽�
                }
            }
            else if(s[i-2] == '0') {
                v[i] = v[i-1]; //ǰ��һ���ַ���0����ǰ�ַ����ں���ⷨ��������
            }
            else if(s[i-2]=='1' || (s[i-2] == '2' && s[i-1]-'0'<7)) {
                    v[i] = v[i-1]+v[i-2]; //ֻ����������ⷨ����ǰ�������ĺͣ�11-19��21-26
            }
            else if(s[i-2]-'0'>2 || (s[i-2] == '2' && s[i-1]-'0'>6)) {
                v[i] = v[i-1]; //����26�����
            }
        }
        return v[len];
    }
};

//Second try:
class Solution {
public:
    int numDecodings(string s) {
        int size = s.length();
        if(size == 0 || s[0] == '0') return 0;
        vector<int> res(size+1, 0);
        res[0] = 1; res[1] = 1;
        for(int i=2; i<=size; i++) {
            if((s[i-2] == '0' || s[i-2] > '2') && s[i-1] == '0') return 0;
            if((s[i-2] == '2' || s[i-2] == '1') && s[i-1] == '0') {
                res[i] = res[i-2];
            }
            else if((s[i-2] == '1') || (s[i-2] == '2' && s[i-1] >= '1' && s[i-1] <= '6')) {
                res[i] = res[i-1] + res[i-2];
            }
            else {
                res[i] = res[i-1];
            }
        }
        return res[size];
    }
};