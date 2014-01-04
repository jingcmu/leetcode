//细节题，主要是一些特殊情况 像.和e的位置摆放
class Solution {
public:
    bool isNumber(const char *s) {
        int len, i;
        bool NoPoint = true;
        bool NoE = true;
        bool numeric = false;
        while(s && s[0] == ' ') s++; //去掉前面的空格
        if(s && (s[0] == '+' || s[0] == '-')) s++; //如果有符号位则去掉
        i = len = strlen(s);
        while(s[--i] == ' ') len--; //去掉后面的空格
        if(len <= 0 || s[0] == 'E' || s[0] == 'e') return false; //这些情况统统返回false
        if(len == 1 && s[0] == '.') return false; //数里面包含点是可以的,但是不能只有一个点
        for(i=0; i<len; i++){
            if(s[i] == '.'){ //发现了点要确保出现一个点
                if(NoPoint) {
                    NoPoint = false;
                    continue;
                }
                else return false;
            }
            if((s[i] == 'E' || s[i] == 'e')) {
                if(NoE && numeric) {
                    NoE = false;
                    NoPoint = false; //出现e之后就不能再出现.了
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