class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length(), last_valid = -1, max_len = 0;
        stack<int> left; //只用来保存'('
        for(int i=0; i<len; i++){
            if(s[i] == '(') { 
                left.push(i);
            }
            else {  //如果是')',则看栈里面有没有对应的'('
                if(left.empty()) {
                    last_valid = i;
                }
                else {
                    left.pop(); //用掉一个'('
                    if(left.empty()) { //如果栈为空,说明能一直匹配到上个')'
                        max_len = max(max_len, i - last_valid);
                    }
                    else { //否则,只能用上个'('的位置算
                        max_len = max(max_len, i - left.top());
                    }
                }
            }
        }
        return max_len;
    }
};