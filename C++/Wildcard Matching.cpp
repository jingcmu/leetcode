//迭代版
/*迭代版比较有技巧，
整个框架是个对s的大循环，一直循环到s的结尾，循环中
首先，最简单情况是如果*p为？，则s和p都往后移动一个字符，这是确定的
然后，如果p等于*，先去掉重复的*，p指向*后的位置，用一个指针记住*的位置，
	  另一个指针指向当前s的位置
最后，如果p不等于*，若*p等于*s，则同时往后移动一个字符，
	  否则，若之前出现过*，就让*多匹配掉一个字符，否则返回false
	  在这里，刚才记录的指针就要用上了，p仍然指向*后的位置，s往后移动一个字符
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {  
        bool star = false;  
        const char* starPtr = NULL;  
        const char* starDelPtr = NULL;  
        while(*s != '\0') {  
            if(*p == '?') s++, p++;
			else if(*p == '*') {
				star = true;    //说明出现了*
                while(*p == '*') p++;  //去掉重复的*,p指向*后的位置
                starPtr = p-1;  //指向p最后一个*
                starDelPtr = s; //指向被*抵消掉n(0,1..)个字符后的位置
            }  
			else  {
                if(*s == *p) s++, p++;  
                else if(star == true){  
                    //如果字符不相等,而且p之前出现了*
                    //则让p的*多抵消掉一个字符再进行后续匹配
                    //p指向上个*的位置之后,s指向多抵消一个字符之后的位置
                    s = ++starDelPtr, p = starPtr+1;
                }
                else return false;  //如果没有出现*  
            }  
        }  
        while(*p == '*') p++; //去掉拖尾的所有*
        return *p == '\0';  
    }  
};

//递归版 会超时
/*
递归版的思路比迭代版清晰：
首先，若p或s为\0，则p和s必须都为\0才能匹配，否则失配
其次，若p不为*，则要么*p等于*s，要么*p等于?，否则当前字符就失配，
	  若当前字符匹配，其结果就依赖于后面字符串是否匹配
最后，若p等于*，则先排除多余的连续*，因为连续的*跟一个*是等价的，
      然后看*之后是否还有其他字符，若没有了，则一定匹配，
	  因为*可以代替任意的字符串。
	  若*之后，还存在其他字符，则看s的当前字符是否为\0，若不为\0，
	  则是否匹配依赖于s剩余的字符串与p出现*之后的字符串是否匹配，由于*可以匹配
	  0个到多个字符，所以需要对s循环检测是否匹配p出现*之后的字符串
*/
	  
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0' || *s == '\0') return *p == *s;
		else if(*p == *s || *p == '?') {
            return isMatch(++s, ++p);
        }
		else if(*p == '*') {
            while(*p == '*') ++p;
            if(*p == '\0') return true;
            while(*s++ != '\0') {
                if(isMatch(s, p)) 
                    return true;
            }
        }
        return false;
    }
};

// c语言递归版，会超时
bool match(const char s, const char r) {
  return s==r || (s && r=='?');
}

bool isMatch(char * s, char * r) {
  //removeStar(r);
  if (*r == '\0') return *s == '\0';
  if (*s == '\0') return *r == '\0' || (*r == '*' && isMatch(s, r+1));
  if (*r == '*') {
    if (*(r+1) == '*') return isMatch(s, r+1);
    else return isMatch(s, r+1) || isMatch(s+1, r);
  } else {
    return match(*s, *r) && isMatch(s+1, r+1);
  }
}
