My solution:
//小括号串是一个递归结构，跟单链表、二叉树等递归结构一样，首先想到用递归。
//一步步构造字符串。当左括号出现次数< n 时，就可以放置新的左括号。当右括号出现次数小
//于左括号出现次数时，就可以放置新的右括号。
class Solution {
public:
    void gen(vector<string> &v, int left, int right, string tmp, int n){
        if(left < right || left > n) return;
        if(left == right && left == n) 
            v.push_back(tmp);
        gen(v, left+1, right, tmp+'(', n);
        gen(v, left, right+1, tmp+')', n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v_ret;
        gen(v_ret, 0, 0, "", n);
        return v_ret;
    }
};
