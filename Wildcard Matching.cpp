class Solution {
public:
    bool isMatch(const char *s, const char *p) {  
        bool star = false;  
        const char* starPtr = NULL;  
        const char* starDelPtr = NULL;  
        while(*s != '\0') {  
            if(*p == '?') s++, p++;  
            else if(*p == '*') {  
                while(*p == '*') p++;  
                starPtr = p-1;  //指向p最后一个*
                starDelPtr = s; //指向被*抵消掉n(0,1..)个字符后的位置
                star = true;    //说明出现了*
            }  
            else {  
                if(*s == *p) s++, p++;  
                else {  
                    //如果字符不相等,而且p之前出现了*
                    //则让p的*多抵消掉一个字符再进行后续匹配
                    if(star == true){
                        //p指向上个*的位置之后,s指向多抵消一个字符之后的位置
                        s = ++starDelPtr, p = starPtr+1;
                    }
                    else return false;  //如果没有出现*
                }  
            }  
        }  
        while(*p == '*') p++; //去掉拖尾的所有*
        return *p == '\0';  
    }  
};