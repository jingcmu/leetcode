class Solution {
public:
    bool isMatch(const char *s, const char *p) {  
        if(*p == '\0') return *s == '\0';
        if(*(p+1) != '*') {
            //当前的字符要么相等要么以.来取代
            if(*p == *s || (*p == '.' && *s != '\0')){
                return isMatch(s+1, p+1);
            }
            else{
                return false;
            }
        }
        else{
            //若下个字符为*，当前p的字符也要与s的字符相同或以.取代
            while(*p == *s || (*p == '.' && *s != '\0')){
                //取代的字符个数尝试增加
                if(isMatch(s++, p+2)){
                    return true;
                }
            }
            //当*s == '\0'时
            return isMatch(s, p+2);
        }
    }  
};