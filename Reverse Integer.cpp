class Solution {
public:
   int reverse(int x) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       int res = 0;
       while(x){
           res = res*10+x%10;  //no matter positive or negative
           x/=10;
       }
       return res;
   }
};