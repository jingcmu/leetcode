class Solution {
public:
    int getLen(int x){
        int len = 0;
        while(x){
            len++;
            x/=10;
        }
        return len;
    }
    int reverse(int x) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       int res = 0;
       while(x){
           res = res*10+x%10;
           x/=10;
       }
       return res;
   }
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = getLen(x);
        int left, right, base = 1;
        if(x<0){
            return false;
        }
        for(int i=0; i<len/2; i++){
            base*=10;
        }
        if(len%2){
            left = x/(base*10);
            right = x%base;
        }
        else{
            left = x/base;
            right = x%base;
        }
        if(right == reverse(left)){
            return true;
        }
        else{
            return false;
        }
    }
};