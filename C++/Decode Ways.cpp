//跟Climbing Stairs很类似，不过多加一些判断逻辑
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
            if(s[i-1] == '0') { //如果当前的字符是0，则必须是10或者20才有解
                if(s[i-2]-'0' <= 2 && s[i-2]-'0' > 0) {
                    v[i] = v[i-2]; //有解，但是只能是2个数一起解
                }
                else {
                    return 0; //否则无解
                }
            }
            else if(s[i-2] == '0') {
                v[i] = v[i-1]; //前面一个字符是0，则当前字符加在后面解法并不增加
            }
            else if(s[i-2]=='1' || (s[i-2] == '2' && s[i-1]-'0'<7)) {
                    v[i] = v[i-1]+v[i-2]; //只有这种情况解法等于前面两个的和：11-19，21-26
            }
            else if(s[i-2]-'0'>2 || (s[i-2] == '2' && s[i-1]-'0'>6)) {
                v[i] = v[i-1]; //大于26的情况
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