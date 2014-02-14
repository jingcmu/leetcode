//水题，把整数反转一下，对比即可
class Solution {
public:
	//把整数反转
    int reverse(int x) {
       int res = 0;
       while(x){
           res = res*10+x%10;
           x/=10;
       }
       return res;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        return x == reverse(x);
    }
};