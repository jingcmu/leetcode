//ˮ�⣬��������תһ�£��Աȼ���
class Solution {
public:
	//��������ת
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