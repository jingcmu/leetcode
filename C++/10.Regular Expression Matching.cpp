// 最佳解法
bool match(const char s, const char r) {
  return s==r || (s && r=='.');
}

bool is_match(const char * s, const char * r) {
  if (!*r) {
    return !*s;
  }
  // Malformed regex handling here:
  // ASSERT(*r != ‘*’);
  if (*(r+1) == '*') {
    return is_match(s, r+2) || (match(*s, *r) && is_match(s+1, r));
  } else {
    return match(*s, *r) && is_match(s+1, r+1);
  }
}

/*p是正则表达式，s为字符串
1.如果p为空串 则s必须为空串才匹配
2.如果非空, 则分2种情况讨论
  a.如果下一个字符非*号，则当前的字符要么相等要么p以.来取代s中的字符，且s中必须有字符（.不能匹配/0）
    如果满足以上条件，则递归从s+1，p+1进行判断
  b.如果下一个字符是*号，则当前p的字符也要与s的字符相同或以.取代，不同的是p中的*号可以不断蚕食s中的字符直到/0
    因此递归是s++，p+2，直到s为\0时
*/
// 2015-05-17 C++
class Solution {
public:
    bool isMatch(string s, string p) {  
        if (p.length() == 0) return s.length() == 0;
        if (p[1] != '*') {
            if (p[0] == s[0] || (p[0] == '.' && s.length() != 0))
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        } else {
            while (p[0] == s[0] || (p[0] == '.' && s.length() != 0)) {
                if(isMatch(s, p.substr(2))) {
                    return true;
                }
                s = s.substr(1);
            }
            return isMatch(s, p.substr(2));
        }
    }
};

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
            //匹配掉0个或多个字符
            while(*p == *s || (*p == '.' && *s != '\0')){
                //取代的字符个数尝试增加
                if(isMatch(s++, p+2)){
                    return true;
                }
            }
            //匹配掉0个字符
            return isMatch(s, p+2);
        }
    }  
};
